/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_module.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 20:47:51 by tbui              #+#    #+#             */
/*   Updated: 2016/08/22 20:47:53 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char			**extract_path_alloc(t_qlist *queue)
{
	int			i;
	size_t		longest;
	char		**path_rev;
	int			j;

	i = 1;
	longest = 0;
	while (queue)
	{
		i++;
		if (ft_strlen((char *)queue->content) > longest)
			longest = ft_strlen((char *)queue->content);
		queue = queue->next;
	}
	if (!(path_rev = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	j = i;
	i = 0;
	while (i < j + 1)
	{
		path_rev[i] = ft_strnew(longest);
		i++;
	}
	return (path_rev);
}

int				path_established(t_qlist *queue, char **path)
{
	t_qlist		*tmp;
	char		*start;
	int			i;
	int			k;

	i = 0;
	k = 0;
	tmp = queue;
	while (tmp->s_e != 1 && tmp)
		tmp = tmp->next;
	start = tmp->content;
	while (ft_strcmp(path[i], "\0") != 0)
	{
		if (ft_strcmp(path[i], start) == 0)
			return (1);
		i++;
	}
	return (0);
}

char			**reverse_path_arr(char **new, char **path, t_qlist *queue)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (ft_strcmp("\0", path[i]) != 0)
		i++;
	i--;
	while (i >= 0)
	{
		new[k] = ft_strcpy(new[k], path[i]);
		i--;
		k++;
	}
	free_path_array(path, queue);
	return (new);
}

void			free_path_array(char **path, t_qlist *queue)
{
	int		i;
	int		k;
	t_qlist	*tmp;

	i = 0;
	k = 0;
	tmp = queue;
	while (tmp)
	{
		tmp = tmp->next;
		k++;
	}
	while (i < k)
	{
		free(path[i]);
		path[i] = NULL;
		i++;
	}
	free(path);
	path = NULL;
}

char			**extract_path(t_qlist *queue)
{
	int			i;
	char		**path;
	char		*next;
	t_qlist		*beg;

	beg = queue;
	path = extract_path_alloc(queue);
	i = 0;
	while (queue->s_e != 2 && queue->next)
		queue = queue->next;
	path[i] = ft_strcpy(path[i], (char *)queue->content);
	next = queue->parent;
	queue = beg;
	i++;
	while (path_established(queue, path) == 0)
	{
		queue = beg;
		while (ft_strcmp(next, (char *)queue->content) != 0)
			queue = queue->next;
		path[i] = ft_strcpy(path[i], (char *)queue->content);
		i++;
		next = queue->parent;
	}
	path = reverse_path_arr_alloc(path, queue);
	return (path);
}
