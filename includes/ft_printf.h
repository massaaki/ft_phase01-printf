
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

// temporary library
# include <stdio.h>

// Mandatory Conventions
# define FORMAT_SIGNED_INT 0
# define FORMAT_UNSIGNED_INT 1
# define FORMAT_SINGLE_CHAR 2
# define FORMAT_STRING 3
# define FORMAT_POINTER 4
# define FORMAT_HEX_UPPER 5
# define FORMAT_HEX_LOWER 6
# define FORMAT_PERCENT 7

int ft_printf(const char *input_str, ...);
int ft_rule_identify(char *str);
int rule_signed_int(int value);

#endif