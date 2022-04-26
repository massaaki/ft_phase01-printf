#include "ft_printf.h"

unsigned int ft_rule_percent(void)
{
	return write(1, "%", 1);
}