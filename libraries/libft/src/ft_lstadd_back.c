/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 03:07:19 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/27 03:07:20 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*current;

	if (!lst || !new_lst)
		return ;
	current = *lst;
	if (current == NULL)
		*lst = new_lst;
	else
	{
		current = ft_lstlast(*lst);
		current->next = new_lst;
	}
}
