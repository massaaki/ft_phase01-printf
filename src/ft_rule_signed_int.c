#include "ft_printf.h"

int ft_rule_signed_int(int arg)
{
	char *result;
	unsigned int length;

	result = ft_itoa(arg);
	length = write(1, result, ft_strlen(result));
	free(result);
	return length;
}