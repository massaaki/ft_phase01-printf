/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 03:09:50 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/27 03:18:39 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input_str, ...)
{
	va_list			ap;
	unsigned int	printed;

	printed = 0;
	va_start(ap, input_str);
	while (*input_str)
	{
		if ((*input_str) == '%')
			printed += ft_rule_to_str(&input_str, &ap);
		else
		{
			printed++;
			write(1, input_str, 1);
		}
	input_str++;
	}
	va_end(ap);
	return (printed);
}

unsigned int	ft_rule_to_str(const char **str, va_list *ap)
{
	int	rule_type;

	rule_type = ft_rule_identify(str);
	if (rule_type == FORMAT_SIGNED_INT)
		return (ft_rule_signed_int(va_arg(*ap, int)));
	if (rule_type == FORMAT_UNSIGNED_INT)
		return (ft_rule_unsigned_int(va_arg(*ap, unsigned int)));
	if (rule_type == FORMAT_SINGLE_CHAR)
		return (ft_rule_char(va_arg(*ap, int)));
	if (rule_type == FORMAT_STRING)
		return (ft_rule_str(va_arg(*ap, char *)));
	if (rule_type == FORMAT_POINTER)
		return (ft_rule_pointer(va_arg(*ap, unsigned long long)));
	if (rule_type == FORMAT_HEX_LOWER)
		return (ft_rule_hex_lower(va_arg(*ap, unsigned int)));
	if (rule_type == FORMAT_HEX_UPPER)
		return (ft_rule_hex_upper(va_arg(*ap, unsigned int)));
	if (rule_type == FORMAT_PERCENT)
		return (ft_rule_percent());
	return (-1);
}
