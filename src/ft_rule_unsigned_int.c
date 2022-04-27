/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule_unsigned_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 03:10:23 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/27 03:16:02 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_rule_unsigned_int(unsigned int arg)
{
	char			*result;
	unsigned int	length;

	result = ft_itoa_unsigned(arg);
	length = write(1, result, ft_strlen(result));
	free(result);
	return (length);
}
