#include "ft_printf.h"

unsigned int ft_rule_hex_lower(unsigned int arg)
{
	char *result;
	unsigned int length;

	result = ft_unsigned_i_to_hex(arg);
	length = write(1, result, ft_strlen(result));
	free(result);
	return length;
}