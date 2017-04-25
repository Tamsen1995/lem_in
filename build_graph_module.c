/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_graph_module.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 21:36:59 by tbui              #+#    #+#             */
/*   Updated: 2016/08/22 21:37:04 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t				get_longest_room(t_list *rooms)
{
	size_t		longest;
	t_list		*tmp_rms;

	tmp_rms = rooms;
	while (tmp_rms->next)
	{
		if (ft_strlen((char *)tmp_rms->content) > longest)
			longest = ft_strlen((char *)tmp_rms->content);
		tmp_rms = tmp_rms->next;
	}
	return (longest);
}

char				***alloc_strings(char ***graph, \
size_t longest, int nbr_rooms)
{
	int			i;
	int			k;

	i = 0;
	k = 0;
	while (i < nbr_rooms)
	{
		k = 0;
		while (k < nbr_rooms)
		{
			graph[i][k] = ft_strnew((size_t)longest);
			k++;
		}
		i++;
	}
	return (graph);
}

char				***allocate_graph(int nbr_rooms, t_list *rooms)
{
	t_list		*tmp_rms;
	int			i;
	char		***graph;
	size_t		longest;

	longest = get_longest_room(rooms);
	tmp_rms = rooms;
	i = 0;
	nbr_rooms++;
	if (!(graph = (char ***)malloc(sizeof(char **) * nbr_rooms)))
		return (NULL);
	while (i < nbr_rooms)
	{
		if (!(graph[i] = (char **)malloc(sizeof(char *) * nbr_rooms)))
			return (NULL);
		i++;
	}
	graph = alloc_strings(graph, longest, nbr_rooms);
	return (graph);
}

int					nbr_room_connects(t_list *room, t_clist *connects)
{
	char		*tmp_room;
	t_clist		*tmp_conns;
	int			nbr_conns;

	nbr_conns = 0;
	tmp_room = (char *)room->content;
	tmp_conns = connects;
	while (tmp_conns)
	{
		if (ft_strcmp(tmp_room, (char *)tmp_conns->one) == 0 || \
			ft_strcmp(tmp_room, (char *)tmp_conns->two) == 0)
			nbr_conns++;
		tmp_conns = tmp_conns->next;
	}
	return (nbr_conns);
}

char				***enter_rooms_into_graph(char ***graph, \
int nbr_rooms, t_list *rooms)
{
	int			i;
	t_list		*tmp_rms;

	i = 0;
	tmp_rms = rooms;
	while (i < nbr_rooms)
	{
		graph[i][0] = ft_strcpy(graph[i][0], (const char *)tmp_rms->content);
		i++;
		tmp_rms = tmp_rms->next;
	}
	return (graph);
}
