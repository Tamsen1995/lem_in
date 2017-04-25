/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 18:17:35 by tbui              #+#    #+#             */
/*   Updated: 2016/09/06 18:17:36 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*list;

	if (*begin_list)
	{
		list = ft_create_elem(data, 0);
		list->next = *begin_list;
		*begin_list = list;
	}
	else
		*begin_list = ft_create_elem(data, 0);
}

void		queue_elem_front(t_qlist **begin_list, \
void *data, void *parent, int s_e)
{
	t_qlist	*list;

	if (*begin_list)
	{
		list = ft_create_q_elem(data, parent, s_e);
		list->next = *begin_list;
		*begin_list = list;
	}
	else
		*begin_list = ft_create_q_elem(data, parent, s_e);
}

t_qlist		*ft_create_q_elem(void *content, void *parent, int s_e)
{
	t_qlist	*list;

	list = NULL;
	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	if (list)
	{
		list->content = content;
		list->parent = parent;
		list->s_e = s_e;
		list->next = NULL;
	}
	return (list);
}
