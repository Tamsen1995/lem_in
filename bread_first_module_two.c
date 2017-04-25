/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bread_first_module_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 17:39:58 by tbui              #+#    #+#             */
/*   Updated: 2016/09/06 17:39:59 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_lem_in_solve(char **path, \
char ***graph, int **rms_arr, int ants)
{
	int i;
	int nbr_rms;
	int *path_idx;

	i = 0;
	nbr_rms = rms_in_path(path);
	path_idx = get_path_idx(path, graph);
	rms_arr[path_idx[0]][2] = ants;
	move_ants(rms_arr, path_idx, graph, nbr_rms);
}

void			ft_lem_in_breadth_first(char ***graph, \
int **rms_arr, t_list *rooms)
{
	t_qlist		*dequeued;
	t_qlist		*queue;
	t_qlist		*tmp;
	char		**path;

	dequeued = NULL;
	queue = put_node_conns_in_q(graph, rms_arr, rooms, &dequeued);
	tmp = queue;
	while (queue->next)
		queue = queue->next;
	queue->next = dequeued;
	queue = tmp;
	if (validate_path_existence(queue) == 0)
		return ;
	print_info(rooms->duct_info);
	path = extract_path(queue);
	free_link_list_qu(queue);
	ft_lem_in_solve(path, graph, rms_arr, rooms->ants);
	free_link_list(rooms);
}

int				validate_path_existence(t_qlist *queue)
{
	int			flag;
	t_qlist		*tmp;

	flag = 0;
	tmp = queue;
	while (tmp->next)
	{
		if (tmp->s_e == 2)
			flag = 1;
		tmp = tmp->next;
	}
	if (flag == 1)
		return (1);
	else
		return (err_out(0));
}

t_qlist			*put_node_conns_in_q_two(char ***graph, \
int **rms_arr, t_list *rooms, t_qlist *queue)
{
	int i;
	int k;
	int nxt_rm;

	i = 0;
	k = 1;
	i = last_elem_queue(queue, graph);
	while (ft_strcmp(graph[i][k], "\0") != 0)
	{
		nxt_rm = match_rm_w_arr(graph, graph[i][k], rooms);
		if (rms_arr[nxt_rm][3] == 0)
		{
			queue_elem_front(&queue, graph[nxt_rm][0], \
			graph[i][0], rms_arr[nxt_rm][1]);
			rms_arr[nxt_rm][3] = 1;
		}
		k++;
	}
	return (queue);
}

t_qlist			*put_node_conns_in_q(char ***graph, \
int **rms_arr, t_list *rooms, t_qlist **dequeued)
{
	int		i;
	int		k;
	int		nxt_rm;
	t_qlist	*queue;

	k = 1;
	i = 0;
	queue = NULL;
	while (rms_arr[i][1] != 1)
		i++;
	queue_elem_front(&queue, graph[i][0], graph[i][0], rms_arr[i][1]);
	rms_arr[i][3] = 1;
	nxt_rm = match_rm_w_arr(graph, graph[i][1], rooms);
	if (rms_arr[nxt_rm][3] == 0)
	{
		queue_elem_front(&queue, graph[nxt_rm][0], \
		graph[i][0], rms_arr[nxt_rm][1]);
		rms_arr[nxt_rm][3] = 1;
	}
	while (queue->next && fin_in_q(graph, rms_arr, queue) == 0)
	{
		queue = put_node_conns_in_q_two(graph, rms_arr, rooms, queue);
		de_queue_last(queue, dequeued);
	}
	return (queue);
}
