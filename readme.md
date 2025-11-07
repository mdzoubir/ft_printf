# ft_printf — 1337 (Project)

ft_printf is a reimplementation of the standard C library function `printf`. The goal of this project is to reproduce the behaviour of `printf` for a specific set of conversion specifiers and formatting options, while respecting the constraints of the 1337 (42) curriculum.

This repository contains my implementation and tests for the mandatory part of the project.

---

## Table of contents
- Project overview
- Requirements & rules
- Supported specifiers & flags
- Usage
- Compilation
- Examples
- Testing
- Notes & edge cases
- Author

---

## Project overview
Recreate the behaviour of `printf` for common conversions and formatting rules. The implementation must:
- Parse the format string,
- Handle variable arguments (variadic functions),
- Produce an identical output (in characters written) for the supported conversions and flags,
- Return the number of characters printed (like the original).

---

## Requirements & rules
- You must write your own `ft_printf` function with the prototype:
```c
int ft_printf(const char *format, ...);
```
- Allowed system calls and functions:
  - `write`
  - `malloc`, `free` (if you use dynamic memory)
  - The `stdarg` macros: `va_start`, `va_arg`, `va_copy`, `va_end`
  - Helper functions you implemented in your project (e.g., from `libft`) are allowed, except any function that directly prints formatted output (no usage of `printf`, `sprintf`, `snprintf`, `vsnprintf`, etc.)
- Behaviour must match the reference for the supported features, including return value (number of characters printed).

---

## Supported conversion specifiers (Mandatory)
- %c — character
- %s — string (print `(null)` or behave as required by your school rules; typical behaviour prints `(null)` for NULL)
- %p — pointer (printed as `0x` followed by lowercase hexadecimal)
- %d, %i — signed decimal integer
- %u — unsigned decimal integer
- %x — unsigned hexadecimal (lowercase)
- %X — unsigned hexadecimal (uppercase)
- %% — print a literal `%`
---

## Behavioural notes / edge cases
- Negative numbers with precision and width must be correctly

