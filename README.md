*This project has been created as part of the 42 curriculum by gelgasim.*

# ft_printf

## Description

`ft_printf` is a 42 school project that recreates the behavior of the standard C `printf()` function.

The goal is to understand variadic functions in C and learn how formatted output works by implementing a custom printing function.

The library is named `libftprintf.a` and supports the following conversions:

| Conversion | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal format. |
| `%d` | Prints a decimal integer. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints a hexadecimal number using lowercase letters. |
| `%X` | Prints a hexadecimal number using uppercase letters. |
| `%%` | Prints a percent sign. |

## Instructions

### Compilation

Run the following command at the root of the repository:

```bash
make
```

This creates the static library `libftprintf.a`.

Available Makefile rules:

- `make` or `make all`: Compile the project and create the library.
- `make clean`: Remove object files.
- `make fclean`: Remove object files and the library.
- `make re`: Clean and rebuild the library.

### Usage

Include `ft_printf.h` in your C source file:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! Number: %d\n", "world", 42);
    return (0);
}
```

Compile your program with the library:

```bash
cc main.c -L. -lftprintf -o test
```

Run the program:

```bash
./test
```

### Requirements

- A C compiler.
- The `make` utility.
- The `ar` command to create the static library.
- The authorized functions specified by the project subject.
- Libft is permitted.

## Algorithm and Technical Choices

### 1. Parsing the format string

The main function, `ft_printf()`, iterates through the format string one character at a time.

- If the current character is not `%`, it prints the character directly.
- If it encounters `%`, it examines the following character to identify the requested conversion.
- It passes the conversion to a handler function, which selects the appropriate printing function.

This approach separates format-string parsing from conversion handling, making the implementation easier to understand and maintain.

### 2. Handling variadic arguments

The function uses `va_list` to access the variable arguments passed to `ft_printf()`.

- `va_start()` initializes access to the arguments.
- `va_arg()` retrieves the argument corresponding to each conversion.
- `va_end()` finishes argument processing.

This allows the function to handle different argument types according to their format specifiers.

### 3. Printing numbers

Decimal and hexadecimal numbers are printed using recursive functions.

For decimal numbers, division and remainder by 10 are used to extract digits.

For hexadecimal numbers, division and remainder by 16 are used. A character lookup string maps each remainder to its corresponding hexadecimal digit.

Recursion processes the higher-order digits first, then prints the remaining digit when each recursive call returns.

### 4. Printing pointer addresses

Pointer values are converted to an unsigned integer type and printed in hexadecimal format, with the `0x` prefix.

The implementation also handles null pointers according to the expected behavior of the target system and project requirements.

### 5. Counting printed characters

Each printing function returns the number of characters it prints.

The conversion handler collects the count returned by the selected printing function, and `ft_printf()` adds those counts together with ordinary characters printed directly from the format string.

This allows `ft_printf()` to return the total number of characters printed, excluding the terminating null character.

### 6. Data structures

The implementation primarily uses:

- **Character arrays:** Store the format string and hexadecimal digit lookup tables.
- **`va_list`:** Access the variable arguments.
- **Integer variables:** Track the current format-string position and the number of characters printed.

No complex data structures are necessary because the function processes the format string sequentially.

## Resources

### Documentation and references

- [C library reference — printf](https://en.cppreference.com/w/c/io/fprintf.html)
- [Linux manual page — printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html)

### AI usage

AI tools were used as learning and debugging assistants during development.

They helped with:

- Understanding variadic functions and format specifiers.
- Explaining recursive decimal and hexadecimal printing.
- Identifying errors in character-counting logic and return values.
- Understanding pointer formatting and null-pointer handling.

The implementation was developed and reviewed as part of the learning process. AI-generated suggestions were used for guidance and debugging.
