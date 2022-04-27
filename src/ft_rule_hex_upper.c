/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule_hex_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 03:10:02 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/27 03:16:34 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_rule_hex_upper(unsigned int arg)
{
	char			*result;
	unsigned int	length;
	int				index;

	result = ft_unsigned_i_to_hex(arg);
	index = 0;
	while (result[index] != '\0')
	{
		result[index] = ft_toupper(result[index]);
		index++;
	}
	length = write(1, result, ft_strlen(result));
	free(result);
	return (length);
}
