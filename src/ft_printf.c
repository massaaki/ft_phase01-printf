#include "ft_printf.h"

int to_int(void *value);

int ft_printf(const char *input_str, ...)
{
	va_list ap;
	// char *arg_converted;
	unsigned int printed;

	printed = 0;
	va_start(ap, input_str);
	while(*input_str)
	{
		if((*input_str) == '%') {
			printed += ft_rule_to_str(&input_str, &ap);
			
			// if (arg_converted == NULL) {
			// 	printf("ERROR DETECTED!!");
			// 	return -1;
			// }
			// write(1, arg_converted, ft_strlen(arg_converted));
			// printed += ft_strlen(arg_converted);
			// free(arg_converted);
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

unsigned int ft_rule_to_str(const char **str, va_list *ap)
{
	int rule_type;
	char *value;
	int index;
	int length;

	value = NULL;
	rule_type = ft_rule_identify(str);
	length = 0;

	if (rule_type == FORMAT_SIGNED_INT)
		return ft_rule_signed_int(va_arg(*ap, int));
	if (rule_type == FORMAT_UNSIGNED_INT)
		return ft_rule_unsigned_int(va_arg(*ap, unsigned int));
	if (rule_type == FORMAT_SINGLE_CHAR)
		return ft_rule_char((char)va_arg(*ap, int));
	if (rule_type == FORMAT_STRING)
		return ft_rule_str(va_arg(*ap, char *));
	if (rule_type == FORMAT_POINTER)
	{
		value = ft_llong_i_to_hex((unsigned long long) va_arg(*ap, unsigned long long));
		length = ft_strlen(value);
	}
	if (rule_type == FORMAT_HEX_LOWER)
	{
		value = ft_unsigned_i_to_hex(va_arg(*ap, unsigned int));
		length = ft_strlen(value);
	}
	if (rule_type == FORMAT_HEX_UPPER)
	{
		value = ft_unsigned_i_to_hex(va_arg(*ap, unsigned int));
		index = 0;
		while (value[index] != '\0')
		{
			value[index] = ft_toupper(value[index]);
			index++;
		}
		length = ft_strlen(value);
	}
	if (rule_type == FORMAT_PERCENT)
	{
		value = ft_strdup("%");
		length = ft_strlen(value);
	}

	write(1, value, length);
	free(value);
	return length;
}
