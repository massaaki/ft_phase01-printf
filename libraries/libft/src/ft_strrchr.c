/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 03:09:26 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/27 03:09:27 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr_s;

	ptr_s = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (*(ptr_s + i) == (char)c)
			return (ptr_s + i);
		i--;
	}
	if (c == '\0')
		return (ptr_s + ft_strlen(s) + 1);
	return (NULL);
}
