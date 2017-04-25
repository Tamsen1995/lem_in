/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_graph_module_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:23:44 by tbui              #+#    #+#             */
/*   Updated: 2016/09/06 16:23:46 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char				***enter_connect_row(char ***graph, int nbr_rooms, \
char *room, char *conn)
{
	int i;
	int k;

	i = 0;
	k = 1;
	while (ft_strcmp(room, graph[i][0]) != 0 && i < nbr_rooms)
		i++;
	while (ft_strcmp("\0", graph[i][k]) != 0)
		k++;
	ft_strcpy(graph[i][k], conn);
	return (graph);
}

char				***enter_connections(char ***graph, int nbr_rooms, \
t_clist *connects)
{
	t_clist *tmp_conns;

	tmp_conns = connects;
	while (tmp_conns)
	{
		graph = enter_connect_row(graph, nbr_rooms, \
			(char *)tmp_conns->one, (char *)tmp_conns->two);
		graph = enter_connect_row(graph, nbr_rooms, \
			(char *)tmp_conns->two, (char *)tmp_conns->one);
		tmp_conns = tmp_conns->next;
	}
	return (graph);
}

char				***build_graph(t_list *rooms, t_clist *connects)
{
	int			nbr_rooms;
	char		***graph;
	t_list		*tmp_rms;

	tmp_rms = rooms;
	nbr_rooms = 0;
	while (tmp_rms)
	{
		tmp_rms = tmp_rms->next;
		nbr_rooms++;
	}
	graph = allocate_graph(nbr_rooms, rooms);
	graph = enter_rooms_into_graph(graph, nbr_rooms, rooms);
	graph = enter_connections(graph, nbr_rooms, connects);
	return (graph);
}
