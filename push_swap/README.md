*This project has been created as part of the 42 curriculum by chbeseme, tavenel.*

# push_swap

## Description

`push_swap` sorts a list of distinct integers using two stacks (`a` and `b`) and a limited set of operations. The program prints, on the standard output, the sequence of operations that leaves stack `a` sorted in ascending order (smallest number on top) and stack `b` empty.

The goal of the project is to experience algorithmic complexity concretely: the cost of an algorithm is measured in **number of Push_swap operations generated**, not in CPU time.

The binary embeds four strategies and can pick one at runtime:

| Selector | Strategy | Complexity (in operations) |
|---|---|---|
| `--simple` | Selection sort (min extraction) | O(n²) |
| `--medium` | Chunk-based sort (√n chunks) | O(n√n) |
| `--complex` | LSD radix sort on ranks | O(n log n) |
| `--adaptive` (default) | Chooses one of the above from the measured disorder | O(n²), O(n√n) or O(n log n) depending on the regime |

### Operations

`sa`, `sb`, `ss` (swap), `pa`, `pb` (push), `ra`, `rb`, `rr` (rotate), `rra`, `rrb`, `rrr` (reverse rotate).

### Data structures

Each stack is a plain `int` array with an explicit size; the top of the stack is index `0`. Both arrays are allocated with capacity `n` (every element may end up in either stack). No global variables are used. Moving elements in an array costs O(n) CPU time, but this does not matter for the score: only the number of operations printed counts.

## Instructions

### Compilation

```
make        # builds push_swap
make clean  # removes object files
make fclean # removes object files and the binary
make re     # fclean + all
```

The project is compiled with `cc -Wall -Wextra -Werror`.

### Usage

```
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <int> <int> ...
```

- The first integer is the top of stack `a`.
- Without a selector, `--adaptive` is used.
- Without any argument, nothing is printed.
- On invalid input (non-integer, out of `int` range, duplicate, ...), `Error` followed by a newline is printed on **stderr**.
- With `--bench`, statistics are printed on **stderr** after sorting: disorder (as a percentage with two decimals), strategy name and complexity class, total number of operations and the count of each operation. The operations themselves stay on stdout.

### Examples

```
$ ./push_swap 2 1 3 6 5 8
$ ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK
$ ./push_swap --bench $ARG 2> bench.txt | ./checker_linux $ARG
$ ./push_swap --simple 3 2 3
Error
```

## Algorithms

### Preprocessing: normalization

Before sorting, every value is replaced by its **rank** in the sorted list (0 to n-1). The relative order is unchanged, so the disorder is the same, but the strategies can work on a compact range of small non-negative integers (negative values and `INT_MIN`/`INT_MAX` need no special handling afterwards).

### Disorder metric

The disorder is computed **before any move**:

```
disorder = mistakes / total_pairs
```

A *mistake* is a pair `(i, j)` with `i < j` and `a[i] > a[j]` (an inversion), and `total_pairs = n(n-1)/2`. It is `0` for a sorted stack and `1` for a stack sorted in reverse. A uniformly random permutation has an expected disorder of `0.5`, since each pair is inverted with probability 1/2. Computing it costs O(n²) CPU time and generates no operation.

### Simple: selection sort, O(n²)

1. Find the minimum of `a`.
2. Bring it to the top with `ra` or `rra`, whichever is shorter.
3. `pb`.
4. Repeat until `a` is sorted (or one element is left), then `pa` everything back.

Minimums are pushed in increasing order, so `b` ends with the largest on top and the `pa` sequence rebuilds `a` in ascending order. Each extraction costs at most `|a|/2` rotations plus one push, so the total is at most about `n²/4 + 2n` operations: **O(n²)**. The early exit when `a` is already sorted saves operations on nearly sorted inputs.

### Medium: chunk sort, O(n√n)

Phase 1 (`a` → `b`): the ranks are split into chunks of size `√n`. We push the elements of chunk 0, then chunk 1, and so on, using `ra` to skip elements that are not in the current chunk. After a push, if the element is in the lower half of its chunk, `rb` sends it to the bottom of `b`; elements of the upper half stay near the top.

Phase 2 (`b` → `a`): repeatedly bring the maximum of `b` to the top (`rb` or `rrb`, whichever is shorter) and `pa` it.

Complexity: phase 1 does at most one pass over `a` per chunk, and there are `√n` chunks, so at most about `n√n + 2n` operations. In phase 2, thanks to the half-chunk rotation, the maximum is always within about `√n` positions of the top or the bottom of `b` (sketch of the argument), so each extraction costs O(√n) and the total is **O(n√n)**.

### Complex: radix sort, O(n log n)

LSD radix sort on the ranks, processing the bits from the least to the most significant. For each bit: every element of `a` is either pushed to `b` (bit = 0) or rotated (`ra`, bit = 1), then everything in `b` is pushed back with `pa`. There are `⌈log₂ n⌉` passes and each pass costs at most `2n` operations, so the total is at most `2n⌈log₂ n⌉`: **O(n log n)**.

### Adaptive strategy

The disorder is measured once, then the strategy is chosen:

| Disorder | Strategy | Class |
|---|---|---|
| `< 0.2` | Selection sort | O(n²) |
| `0.2 ≤ d < 0.5` | Chunk sort | O(n√n) |
| `≥ 0.5` | Radix sort | O(n log n) |

Rationale for the thresholds (imposed by the subject, which fixes the complexity target of each regime):

- Below `0.2`, the stack is close to sorted. The quadratic method is acceptable because its early exit stops as soon as `a` is sorted, and the radix/chunk overhead (full passes regardless of the input) is not worth it.
- Between `0.2` and `0.5`, the stack is partly sorted but still messy, so the intermediate O(n√n) method is used.
- At `0.5` and above, the stack is at least as disordered as a random permutation (expected disorder `0.5`), which is the case where an O(n log n) method pays off the most.

### Space complexity

All strategies use the two arrays of size `n` (O(n)) plus O(1) extra variables. The disorder computation uses O(1) extra space.

## Performance

| Input size | Strategy | Operations (measured) | Target |
|---|---|---|---|
| 100 | adaptive | _to fill_ | < 700 (excellent), < 2000 (pass) |
| 500 | adaptive | _to fill_ | < 5500 (excellent), < 12000 (pass) |

## Contributions

- **<tavenel>**: stack operations, disorder metric, simple strategy (selection sort), adaptive strategy, medium strategy (chunks), README.
- **<chbeseme>**: argument parsing and options, rank normalization, complex strategy (radix sort), benchmark mode, tests, 

Both learners understand and can explain every part of the code.

## Resources

- Radix sort: https://en.wikipedia.org/wiki/Radix_sort
- Big-O notation: https://en.wikipedia.org/wiki/Big_O_notation
- The push_swap subject (42 curriculum).

### Use of AI

We used IA as a learning assistant during this project.

- Explaining the subject.
- Helping to debug.
- Drafting this README.
