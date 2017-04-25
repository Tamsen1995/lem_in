/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_module.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 13:46:56 by tbui              #+#    #+#             */
/*   Updated: 2016/09/06 13:46:58 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			chck_room_for_spaces(char *str)
{
	int spaces;
	int i;

	i = 0;
	spaces = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && ft_isprint(str[i - 1]) && ft_isprint(str[i + 1]))
			spaces++;
		i++;
	}
	if (spaces != 2)
		return (0);
	return (1);
}

int			check_if_room(char *str)
{
	int i;

	i = 0;
	if (chck_room_for_spaces(str) == 0)
		return (0);
	while (str[i - 1] != ' ')
		i++;
	while (str[i] && '\0')
	{
		while (str[i] != ' ' && str[i] != '\0')
		{
			if (ft_isdigit(str[i]) == 0)
				return (0);
			i++;
		}
		i++;
	}
	return (1);
}

int			room_present(t_list *rooms, char *room)
{
	t_list		*tmp;
	int			present;

	present = 0;
	tmp = rooms;
	while (tmp)
	{
		if (ft_strcmp((char *)tmp->content, room) == 0)
			present = 1;
		tmp = tmp->next;
	}
	if (present == 1)
		return (1);
	else
		return (0);
}

int			check_if_tubes(t_list *rooms, char *str)
{
	int		dash;
	int		i;
	char	**rooms_arr;

	i = 0;
	dash = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			dash++;
		if (str[i] == ' ' || ft_isprint(str[i] == 0))
			return (0);
		i++;
	}
	if (dash != 1)
		return (0);
	rooms_arr = ft_strsplit(str, '-');
	if (room_present(rooms, rooms_arr[0]) == 0)
		return (0);
	if (room_present(rooms, rooms_arr[1]) == 0)
		return (0);
	return (1);
}
