
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

// temporary library
# include <stdio.h>

// Mandatory Conventions
# define FORMAT_SIGNED_INT 1
# define FORMAT_UNSIGNED_INT 2
# define FORMAT_SINGLE_CHAR 3
# define FORMAT_STRING 4
# define FORMAT_POINTER 5
# define FORMAT_HEX_UPPER 6
# define FORMAT_HEX_LOWER 7
# define FORMAT_PERCENT 8

int ft_printf(const char *input_str, ...);
int rule_signed_int(int value);

#endif