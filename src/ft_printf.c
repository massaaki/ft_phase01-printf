#include "ft_printf.h"

int to_int(void *value);

int ft_printf(const char *input_str, ...)
{
  va_list ap;
	char *arg_converted;
	int printed;

	printed = 0;
	va_start(ap, input_str);
	while(*input_str)
  {
		if((*input_str) == '%') {
			arg_converted = ft_rule_to_str(&input_str, &ap);
			write(1, arg_converted, ft_strlen(arg_converted));
			printed += ft_strlen(arg_converted);
			free(arg_converted);
		}
		else {
			printed++;
			write(1, input_str, 1);
		}
			
	input_str++;
  }
   va_end(ap);
	 return (printed);
}

char *ft_rule_to_str(const char **str, va_list *ap)
{
	int rule_type;
	char *value;

	value = NULL;
	rule_type = ft_rule_identify(str);

	if (rule_type == FORMAT_SIGNED_INT)
		value = ft_itoa(va_arg(*ap, int));
	if (rule_type == FORMAT_UNSIGNED_INT)
		value = ft_itoa_unsigned(va_arg(*ap, unsigned int));
	if (rule_type == FORMAT_SINGLE_CHAR) {
		value = (char *)malloc(sizeof(char) + 1);
		value[0] = (char)va_arg(*ap, int);
		value[1] = '\0';
	}

	return value;
}
