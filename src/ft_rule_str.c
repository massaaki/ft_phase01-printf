/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 03:10:20 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/27 03:10:20 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int ft_rule_str(char *arg)
{
	if (arg == NULL)
		return write(1, "(null)", 6);
	return write(1, arg, ft_strlen(arg));
}