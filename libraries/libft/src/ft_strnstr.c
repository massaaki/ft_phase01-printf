/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 03:09:20 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/27 03:09:21 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr_haystack;
	size_t	needle_len;

	ptr_haystack = (char *) haystack;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return (ptr_haystack);
	while (*(ptr_haystack) && (len >= needle_len))
	{
		if (ft_strncmp(needle, ptr_haystack, needle_len) == 0)
			return (ptr_haystack);
		ptr_haystack++;
		len--;
	}
	return (NULL);
}
