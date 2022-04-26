#include "ft_printf.h"

unsigned int ft_rule_str(char *arg)
{
	if (arg == NULL)
		return write(1, "(null)", 6);
	return write(1, arg, ft_strlen(arg));
}