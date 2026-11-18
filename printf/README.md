*This project has been created as part of the 42 curriculum by chbeseme.*

# ft_printf

## Description

**ft_printf** is a project from the 42 curriculum. The goal is to recreate my own version of the standard C `printf` function.

This project helps me understand how variadic functions work in C, how to handle arguments of different types, and how to build a reusable static library.

The function has the following prototype:

```c
int ft_printf(const char *format, ...);
```

It writes the formatted output to the standard output and returns the number of characters printed, like the original `printf`.

The library contains:

- **Main function:** `ft_printf`, which reads the format string and handles each conversion.
- **Conversion functions:** functions to print characters, strings, numbers, hexadecimal values and pointers.

The result is a static library called `libftprintf.a`, which can be reused in future C projects.

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This command compiles all source files and creates the static library `libftprintf.a`.

Other available commands:

```bash
make clean
```
Removes the object files (`.o`).

```bash
make fclean
```
Removes the object files and the library `libftprintf.a`.

```bash
make re
```
Removes the previous files and recompiles the library.

### Usage

To use ft_printf in a C project, include the header file:

```c
#include "ft_printf.h"
```

Then compile your program by linking it with the library:

```bash
cc main.c -L. -lftprintf -o program
```

Run the program:

```bash
./program
```

Example:

```c
#include "ft_printf.h"

int	main(void)
{
	int	len;

	len = ft_printf("Hello %s, I am %d years old! (%x)\n", "42", 25, 255);
	ft_printf("Printed %d characters\n", len);
	return (0);
}
```

## Library Contents

### 1. Supported Conversions

Conversions handled by `ft_printf`.

- `%c`: prints a single character.
- `%s`: prints a string (prints `(null)` if the string is `NULL`).
- `%p`: prints a pointer address in hexadecimal, prefixed with `0x` (prints `(nil)` if the pointer is `NULL`).
- `%d`: prints a signed decimal integer.
- `%i`: prints a signed decimal integer.
- `%u`: prints an unsigned decimal integer.
- `%x`: prints an unsigned integer in lowercase hexadecimal.
- `%X`: prints an unsigned integer in uppercase hexadecimal.
- `%%`: prints a percent sign.

### 2. Main Function

Function used to read the format string.

- `ft_printf`: goes through the format string, prints normal characters as they are, and calls the right function for each conversion. It returns the total number of characters printed, or `-1` if the format is `NULL`.

### 3. Conversion Functions

Functions used to print each type of argument. Each one returns the number of characters it printed.

- `ft_print_char`: prints a character with `write`.
- `ft_print_str`: prints a string, or `(null)` if the string is `NULL`.
- `ft_print_number`: prints a signed integer, and handles `INT_MIN` by using a `long`.
- `ft_print_unsigned`: prints an unsigned integer.
- `ft_print_hex`: prints an unsigned integer in hexadecimal, in lowercase or uppercase.
- `ft_print_ptr`: prints a pointer address in hexadecimal, or `(nil)` if the pointer is `NULL`.

### 4. Variadic Arguments

Macros from `<stdarg.h>` used to read the arguments.

- `va_list`: stores the current position in the list of arguments.
- `va_start`: initializes the list after the last named parameter.
- `va_arg`: reads the next argument with the given type.
- `va_end`: cleans up the list.

## Algorithm and Data Structure

### Algorithm

`ft_printf` reads the format string in **a single pass**, from the first to the last character:

1. A normal character is printed as it is with `ft_print_char`.
2. A `%` followed by a letter is sent to `ft_dispatch`, which chooses the right printing function and reads the matching argument with `va_arg`.
3. Each printing function returns the number of characters it printed, and `ft_printf` adds these values to produce its return value.

The complexity is linear: each character of the format string is read once, and each argument is read once.

**Why a dispatch function?** Each conversion has its own function in its own file, so the code stays short, easy to test one conversion at a time, and easy to extend with a new conversion by adding one line in `ft_dispatch`.

**Why recursion to print numbers?** Digits are found from the last one to the first one (`n % base`), but they must be printed from the first one to the last one. With recursion, the function first prints the digits on the left (`n / base`), then the last digit. This prints the digits in the correct order **without `malloc`, without a temporary buffer and without any risk of memory leak**. The same function logic is used for decimal (base 10) and hexadecimal (base 16).

**Why `write` directly, with no internal buffer?** It keeps the code simple, and the output order is always correct. The cost is more system calls than the real `printf`, which is acceptable for this project.

**Edge cases handled:**

- `INT_MIN`: the integer is copied in a `long` before being negated, because `-INT_MIN` does not fit in an `int`.
- Pointers: they are converted to `unsigned long` to keep the whole 64-bit address.
- `NULL` string: prints `(null)`.
- `NULL` pointer: prints `(nil)`.
- `%x` and `%u` with a negative value: the argument is read as an `unsigned int`, like the real `printf`.
- `%` at the end of the format string: nothing is read after the end of the string.

### Data Structure

This project does not need a dynamic data structure (no linked list, no array, no `malloc`). The data used are simple and chosen on purpose:

- **`va_list`**: a cursor that remembers the position in the list of variadic arguments. It is the only way in C to read a variable number of arguments, and each `va_arg` moves it to the next argument.
- **Base strings** (`"0123456789abcdef"` and `"0123456789ABCDEF"`): lookup tables used to convert a digit between 0 and 15 into its character, with a simple index `base[n % 16]`. It is simpler and safer than testing each value one by one.
- **An `int` counter**: accumulates the number of printed characters, because the function must return it.

## Resources

### Documentation

The following resources helped me understand C programming and the functions used in this project:

- [Linux Manual Pages](https://man7.org/linux/man-pages/) — Documentation about `printf`, `write` and `stdarg`.
- [cppreference](https://en.cppreference.com/w/c) — C language reference and function documentation.
- [GNU Make Manual](https://www.gnu.org/software/make/manual/) — Documentation about Makefiles and compilation.

### AI Usage

I used IA as a learning assistant during this project.

It helped me with the following tasks and parts of the project:

- **Understanding variadic arguments** (`va_list`, `va_start`, `va_arg`, `va_end`): used in `ft_printf.c` and `ft_dispatch`.
- **Creating test cases** to compare my output and return value with the real `printf` (test files are not part of the submitted project).
- **Structuring and writing this README file.**

I used AI explanations to improve my understanding of the code and learn how to solve problems independently.