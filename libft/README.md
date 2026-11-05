*This project has been created as part of the 42 curriculum by chbeseme.*

# Libft

## Description

**Libft** is a project from the 42 curriculum. The goal is to create my own C library by reimplementing several standard C library functions.

This project helps me understand how basic C functions work, how memory is managed, and how to manipulate strings and linked lists.

The library contains:

- **Libc functions:** character checks, string manipulation and memory management.
- **Additional functions:** functions to create, manipulate and transform strings.
- **Linked list functions:** functions to create, modify, iterate through and delete linked lists.

The result is a static library called `libft.a`, which can be reused in future C projects.

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This command compiles all source files and creates the static library `libft.a`.

Other available commands:

```bash
make clean
```
Removes the object files (`.o`).

```bash
make fclean
```
Removes the object files and the library `libft.a`.

```bash
make re
```
Removes the previous files and recompiles the library.

### Usage

To use Libft in a C project, include the header file:

```c
#include "libft.h"
```

Then compile your program by linking it with the library:

```bash
cc main.c -L. -lft -o program
```

Run the program:

```bash
./program
```

## Library Contents

### 1. Character Functions

Functions used to check or convert characters.

- `ft_isalpha`: checks whether a character is a letter.
- `ft_isdigit`: checks whether a character is a digit.
- `ft_isalnum`: checks whether a character is alphanumeric.
- `ft_isascii`: checks whether a character belongs to the ASCII set.
- `ft_isprint`: checks whether a character is printable.
- `ft_toupper`: converts a character to uppercase.
- `ft_tolower`: converts a character to lowercase.

### 2. Memory Functions

Functions used to manipulate memory.

- `ft_memset`: fills a memory area with a specific value.
- `ft_bzero`: sets a memory area to zero.
- `ft_memcpy`: copies memory from one location to another.
- `ft_memmove`: copies memory safely, even when memory areas overlap.
- `ft_memchr`: searches for a character in a memory area.
- `ft_memcmp`: compares two memory areas.
- `ft_calloc`: allocates memory and initializes it to zero.

### 3. String Functions

Functions used to manipulate strings.

- `ft_strlen`: calculates the length of a string.
- `ft_strlcpy`: copies a string with a size limit.
- `ft_strlcat`: concatenates strings with a size limit.
- `ft_strchr`: finds the first occurrence of a character.
- `ft_strrchr`: finds the last occurrence of a character.
- `ft_strncmp`: compares two strings up to a given number of characters.
- `ft_strnstr`: searches for a substring within a limited length.
- `ft_strdup`: duplicates a string.
- `ft_substr`: extracts a substring.
- `ft_strjoin`: joins two strings.
- `ft_strtrim`: removes specified characters from the beginning and end of a string.
- `ft_split`: splits a string into an array of strings.
- `ft_itoa`: converts an integer into a string.
- `ft_strmapi`: creates a new string by applying a function to each character.
- `ft_striteri`: applies a function to each character of a string.

### 4. File Descriptor Functions

Functions used to write characters, strings and numbers to a file descriptor.

- `ft_putchar_fd`: writes a character.
- `ft_putstr_fd`: writes a string.
- `ft_putendl_fd`: writes a string followed by a newline.
- `ft_putnbr_fd`: writes an integer.

### 5. Linked List Functions

Functions used to create and manipulate linked lists.

- `ft_lstnew`: creates a new list element.
- `ft_lstadd_front`: adds an element at the beginning of a list.
- `ft_lstadd_back`: adds an element at the end of a list.
- `ft_lstsize`: counts the elements in a list.
- `ft_lstlast`: returns the last element of a list.
- `ft_lstdelone`: deletes one list element.
- `ft_lstclear`: deletes an entire list.
- `ft_lstiter`: applies a function to each element.
- `ft_lstmap`: creates a new list by applying a function to each element.

## Resources

### Documentation

The following resources helped me understand C programming and the functions implemented in this project:

- [Linux Manual Pages](https://man7.org/linux/man-pages/) — Documentation about standard C and system functions.
- [cppreference](https://en.cppreference.com/w/c) — C language reference and function documentation.
- [GNU Make Manual](https://www.gnu.org/software/make/manual/) — Documentation about Makefiles and compilation.

### AI Usage

I used ChatGPT as a learning assistant during this project.

It helped me with:

- Understanding how standard C functions work and how to reimplement them.
- Understanding linked lists and memory management.
- Creating test programs to check whether my functions work correctly.
- Structuring and writing this README file.

I used AI explanations to improve my understanding of the code and learn how to solve problems independently.