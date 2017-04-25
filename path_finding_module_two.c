/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_module_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:24:39 by tbui              #+#    #+#             */
/*   Updated: 2016/09/06 16:24:40 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				*get_path_idx(char **path, char ***graph)
{
	int			*path_idx;
	int			i;
	int			filled;
	int			idx;

	i = 0;
	while (ft_strcmp(path[i], "\0") != 0)
		i++;
	if (!(path_idx = (int *)malloc(sizeof(int) * i)))
		return (NULL);
	filled = i;
	i = 0;
	while (i < filled)
	{
		idx = match_rm_w_arr_solve(graph, path[i]);
		path_idx[i] = idx;
		i++;
	}
	return (path_idx);
}

int				rms_in_path(char **path)
{
	int i;

	i = 0;
	while (ft_strcmp(path[i], "\0") != 0)
		i++;
	return (i);
}

char			**reverse_path_arr_alloc(char **path, t_qlist *queue)
{
	char		**new;
	int			i;
	size_t		longest;
	int			k;

	i = 0;
	new = NULL;
	longest = 0;
	while (ft_strcmp("\0", path[i]) != 0)
	{
		if (ft_strlen(path[i]) > longest)
			longest = ft_strlen(path[i]);
		i++;
	}
	if (!(new = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	k = i + 1;
	i = 0;
	while (i < k)
	{
		new[i] = ft_strnew(longest + 1);
		i++;
	}
	new = reverse_path_arr(new, path, queue);
	return (new);
}

t_clist			*get_tubes_list(t_list *info, t_list *rooms)
{
	t_clist			*connects;
	t_list			*tmp;

	tmp = info;
	connects = NULL;
	while (tmp)
	{
		if (check_if_tubes(rooms, (char *)tmp->content))
			connects = put_tube_in_list(connects, (char *)tmp->content);
		tmp = tmp->next;
	}
	return (connects);
}
