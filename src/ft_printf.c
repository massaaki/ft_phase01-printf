#include <stdio.h>
#include "ft_printf.h"

void ft_printf(void)
{
  printf("ft_printf called...\n");
  printf("%zu\n", ft_strlen("hello"));
}