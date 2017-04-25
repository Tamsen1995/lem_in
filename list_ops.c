/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 22:06:24 by tbui              #+#    #+#             */
/*   Updated: 2016/08/22 22:06:25 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_link_list(t_list *rooms)
{
	t_list *tmp;

	tmp = rooms;
	while (rooms)
	{
		rooms = tmp;
		tmp = rooms->next;
		free(rooms);
		rooms = NULL;
	}
	return ;
}

void			free_link_list_qu(t_qlist *rooms)
{
	t_qlist *tmp;

	tmp = rooms;
	while (rooms)
	{
		rooms = tmp;
		tmp = rooms->next;
		free(rooms);
		rooms = NULL;
	}
	return ;
}

t_clist			*ft_create_tube(void *one, void *two)
{
	t_clist	*list;

	list = NULL;
	if (!(list = malloc(sizeof(t_clist))))
		return (NULL);
	if (list)
	{
		list->one = one;
		list->two = two;
		list->occu = FALSE;
		list->next = NULL;
	}
	return (list);
}

int				ft_list_push_tube(t_clist **begin_list, void *one, void *two)
{
	t_clist		*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
		{
			if (!list)
				return (err_out(0));
			if (list->next)
				list = list->next;
		}
		list->next = ft_create_tube(one, two);
	}
	else
		*begin_list = ft_create_tube(one, two);
	return (1);
}

t_clist			*put_tube_in_list(t_clist *connects, char *str)
{
	char		**con;

	con = ft_strsplit(str, '-');
	if (ft_list_push_tube(&connects, con[0], con[1]) == 0)
		return (NULL);
	return (connects);
}
