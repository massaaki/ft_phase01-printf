#include "libft.h"

static int ft_get_decimal_unsigned(unsigned int n)
{
	unsigned int num;
	unsigned int ref;
	int count;

	ref = 1;
	count = 0;
	num = n;
	while (num / ref != 0 && ref <= 1000000000)
	{
		count++;
		ref *= 10;
	}
	return (count);
}

static char *ft_alloc_mem_unsigned(unsigned int *num, unsigned int n, int *len)
{
	char *result;

	*num = n;
	result = (char *)malloc((*len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[*len] = '\0';
	return (result);
}

static char *ft_alloc_zero_unsigned(void)
{
	char *result;

	result = (char *)malloc(2 * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char *ft_itoa_unsigned(unsigned int n)
{
	char *result;
	unsigned int num;
	int len;

	len = ft_get_decimal_unsigned(n);
	if (n == 0)
	{
		result = ft_alloc_zero_unsigned();
		if (!result)
			return (NULL);
		return (result);
	}
	else
	{
		result = ft_alloc_mem_unsigned(&num, n, &len);
		if (!result)
			return (NULL);
	}
	while (num > 0)
	{
		result[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (result);
}
