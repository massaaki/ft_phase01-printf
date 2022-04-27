#include "ft_printf.h"

unsigned int ft_rule_pointer(unsigned long long arg)
{
	char *result;
	unsigned int length;

	if (arg == 0)
		return (write(1, "(nil)", 5));
	result = ft_llong_i_to_hex(arg);
	length = write(1, result, ft_strlen(result));
	free(result);
	return length;
}