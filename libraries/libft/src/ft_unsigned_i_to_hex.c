/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_i_to_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 01:12:06 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/27 03:26:58 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_hex_nums_fn2(char *hex_nums);
int		ft_num_length_fn2(unsigned int number);
void	revert_str_fn2(char **str);

char	*ft_unsigned_i_to_hex(unsigned int number)
{
	char				hex_nums[16];
	unsigned long long	rest;
	char				*result;
	int					result_last_index;
	int					index;

	result_last_index = ft_num_length_fn2(number);
	ft_set_hex_nums_fn2(hex_nums);
	result = (char *)malloc(result_last_index * sizeof(char) + 1);
	index = 0;
	while (number / 16 != 0)
	{
		rest = number % 16;
		number /= 16;
		result[index] = hex_nums[rest];
		index++;
	}
	result[index] = hex_nums[number];
	result[index + 1] = '\0';
	revert_str_fn2(&result);
	return (result);
}

void	revert_str_fn2(char **str)
{
	char	temp;
	int		length;
	int		aux_index;
	int		i;

	length = ft_strlen(*str);
	aux_index = length - 1;
	i = 0;
	while (i < (length / 2))
	{
		temp = (*str)[i];
		(*str)[i] = (*str)[aux_index];
		(*str)[aux_index] = temp;
		i++;
		aux_index--;
	}
}

int	ft_num_length_fn2(unsigned int number)
{
	int	qty;

	qty = 0;
	while (number / 16 != 0)
	{
		qty++;
		number /= 16;
	}
	return (qty + 1);
}

void	ft_set_hex_nums_fn2(char *hex_nums)
{
	hex_nums[0] = '0';
	hex_nums[1] = '1';
	hex_nums[2] = '2';
	hex_nums[3] = '3';
	hex_nums[4] = '4';
	hex_nums[5] = '5';
	hex_nums[6] = '6';
	hex_nums[7] = '7';
	hex_nums[8] = '8';
	hex_nums[9] = '9';
	hex_nums[10] = 'a';
	hex_nums[11] = 'b';
	hex_nums[12] = 'c';
	hex_nums[13] = 'd';
	hex_nums[14] = 'e';
	hex_nums[15] = 'f';
}
