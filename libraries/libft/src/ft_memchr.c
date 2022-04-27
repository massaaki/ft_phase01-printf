/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 03:08:09 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/27 03:08:10 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*s_temp;

	s_temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(s_temp + i) == (unsigned char)c)
			return (s_temp + i);
		i++;
	}
	return (NULL);
}
