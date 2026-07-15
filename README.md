*This project has been created as part of the 42 curriculum by mtomanar.*

### Description
The **ft_printf** project is a custom implementation of the famous `printf` function from the standard C library (`libc`). The primary goal of this project is to learn about **variadic functions** in C and how to handle a variable number of arguments using the `<stdarg.h>` macros. 

The resulting library, `libftprintf.a`, supports the following mandatory format specifiers:
- `%c`: Prints a single character.
- `%s`: Prints a string.
- `%p`: Prints a `void *` pointer in hexadecimal format.
- `%d` / `%i`: Prints a decimal (base 10) number.
- `%u`: Prints an unsigned decimal (base 10) number.
- `%x`: Prints a number in hexadecimal (base 16) lowercase format.
- `%X`: Prints a number in hexadecimal (base 16) uppercase format.
- `%%`: Prints a percent sign.

### Instructions

**Compilation:**
To compile the library, run the following command in the root of the repository:
```bash
make
```
This will generate the `libftprintf.a` file. You can also use `make clean` to remove object files, `make fclean` to remove the library and objects, or `make re` to rebuild everything from scratch.

**Usage:**
To use the function in your project, include the header and link the library during compilation:
```c
#include "ft_printf.h"
```
Example compilation command for a test file:
```bash
cc main.c libftprintf.a -I include -o test_program
```

### Algorithm and Data Structure

**Data Structure:**
The project relies on the **`va_list`** structure provided by the `<stdarg.h>` header. This structure holds the information necessary to retrieve additional arguments passed through the ellipsis (`...`) in the function signature.

**Algorithm:**
The implementation follows a **Lookup Table (Dictionary) Pattern** whith Functions Pointers:
1.  **Scanning:** The main function `ft_printf` iterates through the format string. Ordinary characters are printed immediately using `ft_putchar`.
2.  **Dispatching:** When a `%` is encountered, the specifier character is matched against a static lookup table (`t_dict[]`). This table acts as a dictionary, mapping each format charactere directly to its dedicated helper function (`t_prtfunc`) in constant time, replacing nested `if/else`or `switch` structures.
3.  **Recursive Conversion:** For numeric conversions (decimal and hexadecimal), **recursion** is used instead of loops. This choice is justified by the **Norm 4.1** restrictions (25-line limit and prohibition of `for` loops), allowing the function to process digits in the correct order without requiring complex buffer management.
4.  **Pointer Management:** For the `%p` specifier, the address is treated as an `unsigned long` to ensure data integrity on 64-bit architectures, and the output is prefixed with `0x`.
5.  **Reference Passing:** To maintain the correct state of the argument list across the decoupled helper functions, the `va_list` is passed by reference (`va_list *`). This ensures that consuming an argument inside a dictionary helper advances the main argument pointer globally.

### Resources

**References:**
- **Standard Documentation:** `man 3 stdarg` and `man 3 printf`.
- **42 Subject:** `en.subject.printf.pdf`.
- **42 Norm:** `pt_br.norm.pdf` (Version 4.1).
- **Research:** Comparative study on "Architecture of Variadic Functions in Modern Languages" regarding memory safety and stack manipulation.

**AI Usage Report:**
Artificial Intelligence was used as a pedagogical support tool throughout the development of this project. The methodology and tasks included:

- **Methodology:** An iterative "Pair Programming" approach where the AI provided logic guidance and debugging while I implemented the code according to 42's strict coding standards (Norm).
- **File Modularization:** Assistance in splitting the logic into `ft_handler.c` and `ft_handler_nbr.c` to comply with the limit of 5 functions per file.
- **Linker Debugging:** Resolving "undefined reference" and "multiple definition" errors by refining the Makefile rules and removing redundant function definitions.
- **Edge Case Refinement:** Aligning the `%p` output with the Linux standard `(nil)` for NULL pointers and ensuring the `INT_MIN` case was handled correctly in the recursive `ft_putnbr` function.
- **Norm Compliance:** Using AI to pre-scan header files for formatting errors such as `MISSING_IDENTIFIER` or incorrect tabulations before final submission.