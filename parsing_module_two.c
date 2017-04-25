/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_module_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 21:47:59 by tbui              #+#    #+#             */
/*   Updated: 2016/08/22 21:48:00 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			no_double_rooms(t_list *rooms)
{
	t_list *tmp;
	t_list *check;

	tmp = rooms;
	while (tmp)
	{
		check = tmp;
		check = check->next;
		while (check)
		{
			if (ft_strcmp((char *)check->content, \
				(char *)tmp->content) == 0)
				return (0);
			check = check->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

char		*get_room_name(char *str)
{
	char	*name;
	int		i;

	i = 0;
	name = ft_strnew(ft_strlen(str));
	while (str[i] != ' ')
	{
		name[i] = str[i];
		i++;
	}
	name[i++] = '\0';
	return (name);
}

int			is_comment(char *str)
{
	char		*firstwo;
	char		*commenttags;
	int			i;

	i = 0;
	commenttags = "#";
	firstwo = ft_strnew(ft_strlen(str));
	while (i < 1 && str[i])
	{
		firstwo[i] = str[i];
		i++;
	}
	if (ft_strcmp(firstwo, commenttags) == 0)
		return (1);
	return (0);
}

t_list		*get_room_list(t_list *info, int ants)
{
	t_list *rooms;
	t_list *tmp;

	tmp = info;
	rooms = NULL;
	while (tmp)
	{
		if (check_if_room((char *)tmp->content) == 1)
			ft_list_push_back(&rooms, \
			get_room_name((char *)tmp->content), ants);
		tmp = tmp->next;
	}
	return (rooms);
}

int			right_format(t_list *info, t_list *rooms)
{
	t_list		*tmp;
	int			flag;

	flag = 0;
	tmp = info->next;
	while (tmp)
	{
		if (check_if_room((char *)tmp->content))
			flag = 1;
		if (flag == 1 && check_if_tubes(rooms, (char *)tmp->content))
			flag = 2;
		if (flag == 2 && check_if_room((char *)tmp->content))
			return (0);
		if (check_if_room((char *)tmp->content) == 0 && \
			check_if_tubes(rooms, (char *)tmp->content) == 0 \
			&& is_comment((char *)tmp->content) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
