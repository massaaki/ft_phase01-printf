/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 03:10:12 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/27 03:11:50 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_rule_pointer(unsigned long long arg)
{
	char			*result;
	unsigned int	length;

	if (arg == 0)
		return (write(1, "(nil)", 5));
	result = ft_llong_i_to_hex(arg);
	length = write(1, result, ft_strlen(result));
	free(result);
	return (length);
}
