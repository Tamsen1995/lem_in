/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bread_first_module.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 22:03:06 by tbui              #+#    #+#             */
/*   Updated: 2016/08/22 22:03:07 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				match_rm_w_arr(char ***graph, char *room, t_list *rooms)
{
	int		i;
	int		nbr_rms;

	nbr_rms = ft_nbr_rms(rooms);
	i = 0;
	while (ft_strcmp(graph[i][0], room) != 0 && i < nbr_rms - 1)
	{
		i++;
	}
	return (i);
}

void			de_queue_last(t_qlist *queue, t_qlist **dequeued)
{
	t_qlist		*curr;

	curr = queue->next;
	while (curr->next != NULL && curr != NULL)
	{
		queue = curr;
		curr = curr->next;
	}
	queue_elem_front(dequeued, (char *)curr->content, \
	(char *)curr->parent, curr->s_e);
	free(queue->next);
	queue->next = NULL;
}

int				last_elem_queue(t_qlist *queue, char ***graph)
{
	int			i;
	t_qlist		*tmp_queue;
	char		*last_elem;

	i = 0;
	tmp_queue = queue;
	while (tmp_queue->next)
		tmp_queue = tmp_queue->next;
	last_elem = (char *)tmp_queue->content;
	while (ft_strcmp(graph[i][0], last_elem) != 0)
		i++;
	return (i);
}

int				fin_in_q(char ***graph, int **rms_arr, t_qlist *queue)
{
	int			fin;
	t_qlist		*tmp_q;

	fin = 0;
	tmp_q = queue;
	while (rms_arr[fin][1] != 2)
		fin++;
	while (queue)
	{
		if (ft_strcmp(graph[fin][0], queue->content) == 0)
		{
			queue->s_e = 2;
			queue = tmp_q;
			return (1);
		}
		queue = queue->next;
	}
	queue = tmp_q;
	return (0);
}

int				ft_nbr_rms(t_list *rooms)
{
	int			i;
	t_list		*tmp_rms;

	i = 0;
	tmp_rms = rooms;
	while (tmp_rms)
	{
		i++;
		tmp_rms = tmp_rms->next;
	}
	tmp_rms = NULL;
	return (i);
}
