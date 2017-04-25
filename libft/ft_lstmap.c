/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:25:58 by tbui              #+#    #+#             */
/*   Updated: 2015/11/30 18:31:07 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *adding;
	t_list *tmp;

	newlist = f(lst);
	tmp = newlist;
	lst = lst->next;
	while (lst != NULL)
	{
		adding = f(lst);
		tmp->next = adding;
		tmp = adding;
		lst = lst->next;
	}
	return (newlist);
}
