#include "ft_printf.h"

unsigned int ft_rule_char(char arg)
{
	write(1, &arg, 1);
	return (1);
}