/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:19:16 by tbui              #+#    #+#             */
/*   Updated: 2016/09/06 16:19:19 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "get_next_line.h"
# include "libft.h"

# define TRUE 1
# define FALSE 0

typedef	int		t_bool;

typedef	struct	s_alist
{
	void			*one;
	void			*two;
	t_bool			occu;
	struct s_alist	*next;
}				t_clist;

void			print_info(t_list *info);
int				val_rms_nd_tbs(t_list *info, t_list *rooms);
void			print_ant(int ant, char ***graph, int path);
int				ant_cond_chkr(int **rms_arr, \
char ***graph, int *path_idx, int *i);
int				rm_mpty(int **rms_arr, char ***graph, \
int *path_idx, int nbr_rms);
int				rms_in_path(char **path);
void			ft_lem_in_two(t_list *rooms, t_clist *connects);
int				cmp_rms_w_con(t_list *rooms, char *rms_one, char *rms_two);
int				tubes_nd_rooms_vld(t_list *rooms, t_clist *connects);
int				validate_path_existence(t_qlist *queue);
int				match_rm_w_arr_solve(char ***graph, char *room);
int				*get_path_idx(char **path, char ***graph);
int				ants_at_end(int **rms_arr, int last, int nbr_ants);
int				**transfer_ants(int **rms_arr, \
char ***graph, int *path_idx, int i);
void			out_put_ants(int **rms_arr, char ***graph, \
int *path_idx, int nbr_rms);
void			move_ants(int **rms_arr, int *path_idx, \
char ***graph, int nbr_rms);
void			ft_lem_in_solve(char **path, \
char ***graph, int **rms_arr, int ants);
void			ft_lem_in_breadth_first(char ***graph, \
int **rms_arr, t_list *rooms);
void			show_graph_and_rooms_test(char ***graph, int **rms_arr);
void			free_link_list_qu(t_qlist *rooms);
void			free_path_array(char **path, t_qlist *queue);
char			**extract_path(t_qlist *queue);
char			**reverse_path_arr_alloc(char **path, t_qlist *queue);
char			**reverse_path_arr(char **new, char **path, t_qlist *queue);
int				path_established(t_qlist *queue, char **path);
char			**extract_path_alloc(t_qlist *queue);
int				fin_in_q(char ***graph, int **rms_arr, t_qlist *queue);
t_qlist			*put_node_conns_in_q(char ***graph, int \
**rms_arr, t_list *rooms, t_qlist **dequeued);
int				last_elem_queue(t_qlist *queue, char ***graph);
void			de_queue_last(t_qlist *queue, t_qlist **dequeued);
int				match_rm_w_arr(char ***graph, char *room, t_list *rooms);
int				ft_nbr_rms(t_list *rooms);
void			free_link_list(t_list *rooms);
int				**alloc_rooms_arr(int nbr_rooms);
int				**enter_rooms_in_arr(int nbr, int **ret, t_list *rooms);
int				**build_rooms(t_list *rooms);
char			***enter_rooms_into_graph(char ***graph, \
int nbr_rooms, t_list *rooms);
char			***build_graph(t_list *rooms, \
t_clist *connects);
char			***enter_connections(char ***graph, \
int nbr_rooms, t_clist *connects);
char			***enter_connect_row(char ***graph, \
int nbr_rooms, char *room, char *conn);
char			***enter_rooms_into_graph(char ***graph, \
int nbr_rooms, t_list *rooms);
int				nbr_room_connects(t_list *room, t_clist *connects);
char			***allocate_graph(int nbr_rooms, t_list *rooms);
size_t			get_longest_room(t_list *rooms);
char			***alloc_strings(char ***graph, size_t longest, int nbr_rooms);
int				nbr_room_connects(t_list *room, t_clist *connects);
char			***build_graph(t_list *rooms, t_clist *connects);
int				check_st_end(t_list *rooms);
int				get_ants(char *str);
t_list			*start_det(t_list *rooms, t_list *info);
t_list			*end_det(t_list *rooms, t_list *info);
int				no_double_rooms(t_list *rooms);
t_clist			*put_tube_in_list(t_clist *connects, char *str);
t_clist			*get_tubes_list(t_list *info, t_list *rooms);
t_clist			*ft_create_tube(void *one, void *two);
int				ft_list_push_tube(t_clist **begin_list, void *one, void *two);
int				ft_lem_in(t_list *info);
int				right_format(t_list *info, t_list *rooms);
t_list			*get_room_list(t_list *info, int ants);
int				err_out(int i);
int				is_comment(char *str);
void			parsing_validation(t_list *info);
int				check_if_room(char *str);
int				chck_room_for_spaces(char *str);
char			*get_room_name(char *str);
int				check_if_tubes(t_list *rooms, char *str);
int				check_if_tubes_two(t_list *rooms, char *str);
int				compare_strs(char *str1, char *str2);
int				room_present(t_list *rooms, char *namecmp);

#endif
