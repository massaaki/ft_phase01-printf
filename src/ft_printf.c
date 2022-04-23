#include "ft_printf.h"
// #include <stdio.h>

int ft_printf(const char *input_str, ...)
{
  va_list ap;

  va_start(ap, input_str);

  while(*input_str)
  {
    //  if((*input_str) == '%')
    //  {
    //    ft_rule_identify(input_str);
    //  }
    //  else
        write(1, input_str, 1);

    input_str++;
  }
   va_end(ap);
  return (0);
}