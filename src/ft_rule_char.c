#include "ft_printf.h"

unsigned int ft_rule_char(char arg)
{
	return write(1, &arg, 1);
}