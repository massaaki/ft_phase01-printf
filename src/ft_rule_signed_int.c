/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule_signed_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 03:10:15 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/27 03:17:07 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_rule_signed_int(int arg)
{
	char			*result;
	unsigned int	length;

	result = ft_itoa(arg);
	length = write(1, result, ft_strlen(result));
	free(result);
	return (length);
}
