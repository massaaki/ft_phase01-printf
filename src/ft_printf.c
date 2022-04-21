#include "ft_printf.h"
// #include <stdio.h>

int ft_printf(const char *input_str, ...)
{
  va_list ap;

  printf("===> %d\n", FORMAT_UNSIGNED_INT);

  va_start(ap, input_str);

  while(*input_str)
  {
     if((*input_str) == '%' )
     {
       rule_signed_int(va_arg(ap, int));
     }
     else
     {
        write(1, input_str, 1);
     }

    input_str++;
  }

   va_end(ap);

  write(1, "\n", 1);
  return (0);
}