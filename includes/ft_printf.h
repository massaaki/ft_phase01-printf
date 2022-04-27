/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 03:19:19 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/27 03:20:14 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

// Mandatory Conventions
# define FORMAT_SIGNED_INT 0
# define FORMAT_UNSIGNED_INT 1
# define FORMAT_SINGLE_CHAR 2
# define FORMAT_STRING 3
# define FORMAT_POINTER 4
# define FORMAT_HEX_UPPER 5
# define FORMAT_HEX_LOWER 6
# define FORMAT_PERCENT 7

int				ft_printf(const char *input_str, ...);
unsigned int	ft_rule_to_str(const char **str, va_list *ap);
int				ft_rule_identify(const char **str);
int				ft_rule_signed_int(int value);
unsigned int	ft_rule_str(char *arg);
int				ft_rule_unsigned_int(unsigned int arg);
unsigned int	ft_rule_char(char arg);
unsigned int	ft_rule_pointer(unsigned long long arg);
unsigned int	ft_rule_hex_lower(unsigned int arg);
unsigned int	ft_rule_hex_upper(unsigned int arg);
unsigned int	ft_rule_percent(void);

#endif