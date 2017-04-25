/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_ops_module_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:09:04 by tbui              #+#    #+#             */
/*   Updated: 2016/09/06 16:09:05 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		move_ants(int **rms_arr, int *path_idx, char ***graph, int nbr_rms)
{
	int i;
	int nbr_ants;
	int ants_rm;

	nbr_ants = rms_arr[path_idx[0]][2];
	i = nbr_rms - 1;
	while (ants_at_end(rms_arr, match_rm_w_arr_solve(graph, \
	graph[path_idx[nbr_rms - 1]][0]), nbr_ants) != 1)
	{
		ants_rm = rms_arr[match_rm_w_arr_solve(graph, \
		graph[path_idx[nbr_rms - 1]][0])][2];
		if (ant_cond_chkr(rms_arr, graph, path_idx, &i) == 1)
			rms_arr = transfer_ants(rms_arr, graph, path_idx, i);
		if (ants_rm < nbr_ants && \
			rm_mpty(rms_arr, graph, path_idx, nbr_rms)\
			&& i == nbr_rms - 1)
			rms_arr = transfer_ants(rms_arr, graph, path_idx, i);
		if (i <= 1)
		{
			i = nbr_rms;
			out_put_ants(rms_arr, graph, path_idx, nbr_rms);
		}
		i--;
	}
	out_put_ants(rms_arr, graph, path_idx, nbr_rms);
}

void		out_put_ants(int **rms_arr, char ***graph, \
int *path_idx, int nbr_rms)
{
	int i;
	int ant;
	int ants_in_rm;
	int path;

	ant = 1;
	i = nbr_rms - 1;
	while (i > 0)
	{
		path = match_rm_w_arr_solve(graph, graph[path_idx[i]][0]);
		if (rms_arr[path][2] > 0)
		{
			ants_in_rm = rms_arr[path][2];
			while (ants_in_rm > 0)
			{
				if (ant - rms_arr[path][2] >= 0)
					print_ant(ant, graph, path);
				ant++;
				ants_in_rm--;
			}
		}
		i--;
	}
	ft_putstr("\n");
}
