/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:29:44 by tbui              #+#    #+#             */
/*   Updated: 2016/09/06 16:29:46 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			val_rms_nd_tbs(t_list *info, t_list *rooms)
{
	t_list		*tmp_info;
	char		**con;

	tmp_info = info;
	while (tmp_info)
	{
		if (check_if_tubes(rooms, (char *)tmp_info))
		{
			con = ft_strsplit((char *)tmp_info, '-');
			if (cmp_rms_w_con(rooms, con[0], con[1]) == 0)
				return (0);
		}
		tmp_info = tmp_info->next;
	}
	return (1);
}
