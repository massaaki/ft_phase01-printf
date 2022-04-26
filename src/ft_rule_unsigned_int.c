#include "ft_printf.h"

int ft_rule_unsigned_int(unsigned int arg)
{
	char *result;
	unsigned int length;

	result = ft_itoa_unsigned(arg);
	length = write(1, result, ft_strlen(result));
	free(result);
	return length;
}