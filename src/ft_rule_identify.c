#include "ft_printf.h"

/*
 * Receive str starting with zero
 * and return rule identified 
**/
int ft_rule_identify(char *str)
{
  if(!str || (*(str + 1) == '\0'))
    return -1;
  if (*(str + 1) == 'd' || *(str + 1) == 'i')
    return FORMAT_SIGNED_INT;
  if( *(str + 1) == 'u')
    return FORMAT_UNSIGNED_INT;
  if (*(str + 1) == 'c')
    return FORMAT_SINGLE_CHAR;
  if( *(str + 1) == 's')
    return FORMAT_STRING;
  if( *(str + 1) == 'p')
    return FORMAT_POINTER;
  if( *(str + 1) == 'x')
    return FORMAT_HEX_LOWER;
  if( *(str + 1) == 'X')
    return FORMAT_HEX_UPPER;
  if( *(str + 1) == '%')
    return FORMAT_PERCENT;
  return (-1);
}