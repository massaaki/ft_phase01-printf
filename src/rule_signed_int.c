#include "ft_printf.h"

int rule_signed_int(int value)
{
  int qty_printed;

  qty_printed = 5;
  if(value > 1)
  {
    write(1, "(INT_12345)", 11);
  }

    return qty_printed;
}