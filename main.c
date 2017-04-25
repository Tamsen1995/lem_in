/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 20:47:10 by tbui              #+#    #+#             */
/*   Updated: 2016/08/22 20:47:15 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			match_rm_w_arr_solve(char ***graph, char *room)
{
	int i;

	i = 0;
	while (ft_strcmp(graph[i][0], room) != 0 && \
		ft_strcmp(graph[i][0], "\0") != 0)
		i++;
	return (i);
}

void		ft_lem_in_two(t_list *rooms, t_clist *connects)
{
	char	***graph;
	int		**rms_arr;

	graph = build_graph(rooms, connects);
	rms_arr = build_rooms(rooms);
	ft_lem_in_breadth_first(graph, rms_arr, rooms);
	return ;
}

int			ft_lem_in(t_list *info)
{
	t_list		*rooms;
	t_clist		*connects;
	int			ants;

	ants = get_ants((char *)info->content);
	if (ants <= 0)
		return (0);
	rooms = get_room_list(info, ants);
	if (no_double_rooms(rooms) == 0)
		return (0);
	if (right_format(info, rooms) == 0 || val_rms_nd_tbs(info, rooms) == 0)
		return (0);
	connects = NULL;
	connects = get_tubes_list(info, rooms);
	if (connects == NULL)
		return (0);
	rooms = start_det(rooms, info);
	rooms = end_det(rooms, info);
	if (check_st_end(rooms) == 0)
		return (0);
	rooms->duct_info = info;
	ft_lem_in_two(rooms, connects);
	return (1);
}

void		print_info(t_list *info)
{
	t_list *tmp;

	tmp = info;
	while (tmp->next)
	{
		ft_putstr((char *)tmp->content);
		ft_putstr("\n");
		tmp = tmp->next;
	}
	ft_putstr("\n");
}

int			main(void)
{
	char	*line;
	t_list	*info;
	int		info_amt;

	info_amt = 0;
	line = NULL;
	info = NULL;
	while (get_next_line(0, &line) == 1)
	{
		ft_list_push_back(&info, line, 0);
		info_amt++;
	}
	if (info_amt <= 0)
		return (err_out(0));
	if (info_amt == 0)
		return (err_out(0));
	if (ft_lem_in(info) == 0)
		return (err_out(0));
	return (0);
}
