/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule_identify.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 03:10:05 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/27 03:15:08 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Receive str starting with zero
 * and return rule identified 
**/
int	ft_rule_identify(const char **str)
{
	if (!*str || (*(*str + 1) == '\0'))
		return (-1);
	(*str)++;
	if (*(*str) == 'd' || *(*str) == 'i')
		return (FORMAT_SIGNED_INT);
	if (*(*str) == 'u')
		return (FORMAT_UNSIGNED_INT);
	if (*(*str) == 'c')
		return (FORMAT_SINGLE_CHAR);
	if (*(*str) == 's')
		return (FORMAT_STRING);
	if (*(*str) == 'p')
		return (FORMAT_POINTER);
	if (*(*str) == 'x')
		return (FORMAT_HEX_LOWER);
	if (*(*str) == 'X')
		return (FORMAT_HEX_UPPER);
	if (*(*str) == '%')
		return (FORMAT_PERCENT);
	return (-1);
}
