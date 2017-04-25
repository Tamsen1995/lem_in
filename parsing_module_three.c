/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_module_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 21:40:41 by tbui              #+#    #+#             */
/*   Updated: 2016/08/22 21:40:43 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list			*end_det(t_list *rooms, t_list *info)
{
	char		*end;
	t_list		*tmp_info;
	t_list		*tmp_rooms;

	tmp_rooms = rooms;
	tmp_info = info;
	end = "##end";
	while (tmp_info)
	{
		if (ft_strcmp((char*)tmp_info->content, end) == 0)
		{
			tmp_info = tmp_info->next;
			if (check_if_room((char *)tmp_info->content))
			{
				while (ft_strcmp((char *)tmp_rooms->content, \
					get_room_name((char *)tmp_info->content)) != 0)
					tmp_rooms = tmp_rooms->next;
				tmp_rooms->s_e = 2;
			}
		}
		tmp_info = tmp_info->next;
	}
	tmp_rooms = rooms;
	return (tmp_rooms);
}

t_list			*start_det(t_list *rooms, t_list *info)
{
	char		*start;
	t_list		*tmp_info;
	t_list		*tmp_rooms;

	tmp_rooms = rooms;
	tmp_info = info;
	start = "##start";
	while (tmp_info)
	{
		if (ft_strcmp((char*)tmp_info->content, start) == 0)
		{
			tmp_info = tmp_info->next;
			if (check_if_room((char *)tmp_info->content))
			{
				while (ft_strcmp((char *)tmp_rooms->content, \
					get_room_name((char *)tmp_info->content)) != 0)
					tmp_rooms = tmp_rooms->next;
				tmp_rooms->s_e = 1;
			}
		}
		tmp_info = tmp_info->next;
	}
	tmp_rooms = rooms;
	return (tmp_rooms);
}

int				check_st_end(t_list *rooms)
{
	int			flag_st;
	int			flag_end;
	t_list		*tmp;

	tmp = rooms;
	flag_st = 0;
	flag_end = 0;
	while (tmp)
	{
		if (tmp->s_e == 1)
			flag_st = 1;
		if (tmp->s_e == 2)
			flag_end = 1;
		tmp = tmp->next;
	}
	if (flag_st == 1 && flag_end == 1)
		return (1);
	return (0);
}

int				get_ants(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (ft_atoi(str));
}

int				cmp_rms_w_con(t_list *rooms, char *rms_one, char *rms_two)
{
	t_list		*tmp_rms;
	int			flag;
	char		*rm;

	flag = 0;
	tmp_rms = rooms;
	while (tmp_rms)
	{
		rm = (char *)tmp_rms->content;
		if (ft_strcmp(rm, rms_one) == 0 || ft_strcmp(rm, rms_two) == 0)
			flag++;
		tmp_rms = tmp_rms->next;
	}
	ft_putnbr(flag);
	if (flag < 2)
		return (0);
	return (1);
}
