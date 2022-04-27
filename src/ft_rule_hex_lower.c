/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule_hex_lower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 03:09:58 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/27 03:09:58 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int ft_rule_hex_lower(unsigned int arg)
{
	char *result;
	unsigned int length;

	result = ft_unsigned_i_to_hex(arg);
	length = write(1, result, ft_strlen(result));
	free(result);
	return length;
}