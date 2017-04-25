/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_ops_module.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:05:18 by tbui              #+#    #+#             */
/*   Updated: 2016/09/06 16:05:19 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ants_at_end(int **rms_arr, int last, int nbr_ants)
{
	if (rms_arr[last][2] >= nbr_ants)
		return (1);
	else
		return (0);
}

void		print_ant(int ant, char ***graph, int path)
{
	ft_putstr("L");
	ft_putnbr(ant);
	ft_putstr("-");
	ft_putstr(graph[path][0]);
	ft_putstr(" ");
}

int			ant_cond_chkr(int **rms_arr, char ***graph, int *path_idx, int *i)
{
	if (rms_arr[match_rm_w_arr_solve(graph, \
		graph[path_idx[(*i)]][0])][2] == 0 && \
		rms_arr[match_rm_w_arr_solve(graph, \
		graph[path_idx[(*i) - 1]][0])][2] > 0 && \
		(*i) >= 1)
		return (1);
	else
		return (0);
}

int			rm_mpty(int **rms_arr, char ***graph, int *path_idx, int nbr_rms)
{
	if (rms_arr[match_rm_w_arr_solve(graph, \
		graph[path_idx[nbr_rms - 2]][0])][2] > 0)
		return (1);
	return (0);
}

int			**transfer_ants(int **rms_arr, char ***graph, int *path_idx, int i)
{
	int path;
	int before;

	path = match_rm_w_arr_solve(graph, graph[path_idx[i]][0]);
	before = match_rm_w_arr_solve(graph, graph[path_idx[i - 1]][0]);
	rms_arr[before][2]--;
	rms_arr[path][2]++;
	return (rms_arr);
}
