/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 18:18:30 by tbui              #+#    #+#             */
/*   Updated: 2016/09/06 18:18:32 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_elem(void *content, int ants)
{
	t_list	*list;

	list = NULL;
	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	if (list)
	{
		list->content = content;
		list->ants = ants;
		list->next = NULL;
	}
	return (list);
}
