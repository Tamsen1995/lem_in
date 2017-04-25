/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_rooms_arr_module.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 21:41:16 by tbui              #+#    #+#             */
/*   Updated: 2016/08/22 21:41:18 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			**alloc_rooms_arr(int nbr_rooms)
{
	int **ret;
	int i;

	i = 0;
	if (!(ret = (int **)malloc(sizeof(int *) * nbr_rooms)))
		return (NULL);
	while (i < nbr_rooms)
	{
		if (!(ret[i] = (int *)malloc(sizeof(int) * 3)))
			return (NULL);
		i++;
	}
	return (ret);
}

int			**enter_rooms_in_arr(int nbr, int **ret, t_list *rooms)
{
	int			i;
	int			k;
	t_list		*tmp_rms;

	tmp_rms = rooms;
	i = 0;
	k = 0;
	while (i < nbr && tmp_rms)
	{
		ret[i][0] = k;
		if (tmp_rms->s_e == 1)
			ret[i][1] = 1;
		else if (tmp_rms->s_e == 2)
			ret[i][1] = 2;
		else
			ret[i][1] = 0;
		tmp_rms = tmp_rms->next;
		i++;
		k++;
	}
	return (ret);
}

int			**build_rooms(t_list *rooms)
{
	int			**ret;
	t_list		*tmp_rms;
	int			nbr_rooms;

	nbr_rooms = 0;
	tmp_rms = rooms;
	while (tmp_rms)
	{
		nbr_rooms++;
		tmp_rms = tmp_rms->next;
	}
	ret = alloc_rooms_arr(nbr_rooms);
	ret = enter_rooms_in_arr(nbr_rooms, ret, rooms);
	return (ret);
}
