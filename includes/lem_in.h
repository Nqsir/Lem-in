/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 11:47:25 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:39 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define STEP_0 0
# define STEP_1 1
# define STEP_2 2
# define STEP_ERROR 4
# define ROOM 0
# define NODE 1
# define START 0
# define END 1
# define PATH 1000

# include <stdio.h>
# include <limits.h>

# include "../libft/ft_printf/includes/ft_printf.h"
# include "../libft/libft/includes/libft.h"

typedef	size_t		t_id;

typedef struct		s_instruction
{
	char					*str;
	struct s_instruction	*next;
}					t_instruction;

typedef struct		s_path
{
	t_id					*path;
	t_id					value;
	t_id					stop_send;
	struct s_path			*next;
}					t_path;

typedef struct		s_lst
{
	t_id					*lst;
	t_id					value;
}					t_lst;

typedef struct		s_link
{
	t_lst					**path;
	t_id					nb_link;
}					t_link;

typedef struct		s_group_path
{
	t_path					**rep_path;
	t_id					nb_path;
	t_id					tot_shots;
	t_id					cycle;
}					t_group_path;

typedef struct		s_room
{
	char					*name;
	t_id					x;
	t_id					y;
	t_id					nb_ant;
	t_id					ant_n;
	t_id					flag;
}					t_room;

typedef struct		s_box
{
	t_id					nb_room;
	t_id					nb_link;
	t_id					nb_int;
	t_id					nb_strat;
	t_instruction			*instruction;
	t_instruction			*tmp;
	t_id					nb_instruction;
	t_id					i;
	t_id					s_or_e;
	t_id					r_or_n;
	t_id					l;
	t_id					f;
	t_id					test_room;

	t_room					**room;
	t_link					**link;
	t_path					*list_path;
	t_id					size_list_path;
	t_path					*tmp_path;
	t_path					**tab_path;
	t_group_path			**g_path;
}					t_box;

/*
** -----------------------------------   anthill start    ---------------------
*/
t_id				checker(t_box *box);
t_id				commande(t_box *box, t_id step);
t_id				fourmis(char *word, t_box *box);
t_id				liaison(char *str, t_box *box);
t_id				parser(t_box *box);
t_id				salle(t_box *box, t_id type);
/*
** -----------------------------------   anthill end    ---------------------
*/

/*
** -----------------------------------   clear start    ---------------------
*/
t_id				clear_anthill(t_box *box);
t_id				clear_loop_path(t_box *b);
t_id				clear_multi_path(t_box *box);
t_id				clear_room(t_box *box);
t_id				find_road(t_box *box);
/*
** -----------------------------------   clear start    ---------------------
*/

/*
**-----------------------------------   binary start    ---------------------
*/
void				t_path_lst_to_tab(t_box *box);
void				get_path(t_box *box, t_id value);
void				get_cycle(t_box *box);
void				ft_set_tab_at_0(t_box *box, t_lst **bin_start,
									t_lst **bin_tmp);
t_id				ft_init_tab_bin(t_box *box, t_lst **bin, t_id id);
void				ft_init_tmp(t_box *box, t_lst **bin, t_lst **tmp);
void				ft_init_tab_1(t_box *box, t_lst **bin);
void				ft_init_for_bin(t_box *box);
void				ft_match_path(t_box *box);
void				ft_cpy_path_bin(t_box *box, t_id strat);
t_id				*ft_merge_lines_tab_bin(t_box *box, t_lst **tab,
											t_id id, t_id strat);
void				ft_swap_to_bin(t_box *box, t_lst **tab);
void				ft_sort_tab_bin(t_box *box);
int					ft_bin_lem_in(t_box *box);
int					ft_raise_flags(t_box *box, t_lst **bin, t_lst **tmp);
/*
**-----------------------------------   binary end    ---------------------
*/

/*
**-----------------------------------   create start    ---------------------
*/
t_box				*t_box_create(void);
t_group_path		**t_group_path_create_tab(t_id nb_group,
								t_id size_path);
t_group_path		*t_group_path_create_elem(t_id nb_path, t_id size_path);
void				t_instruction_create_list(t_box *box);
t_link				**t_link_create_tab(t_id nb_room, t_id nb_link,
								t_id size_lst, t_id value);
t_link				*t_link_create_elem(t_id nb_link, t_id size_lst,
								t_id value);
t_lst				**t_lst_create_tab(t_id nb_list, t_id size_list,
								t_id value);
t_lst				*t_lst_create_elem(t_id size_list, t_id value);
t_path				**t_path_create_tab(t_id nb_path, t_id size_path);
t_path				*t_path_create_elem(t_id size_path);
t_room				**t_room_create_tab(t_id nb_room);
t_room				*t_room_create_elem(void);
/*
**-----------------------------------   create end    ---------------------
*/

/*
**-----------------------------------   free start   ---------------------
*/
void				ft_free_bin(t_lst **bin_start, t_lst **bin_tmp);
void				t_box_free(t_box *box);
void				t_group_path_free_tab(t_group_path **group_path);
void				t_group_path_free_elem(t_group_path *group_path);
void				t_instruction_free_list(t_box *box);
void				t_link_free_tab(t_link **link);
void				t_link_free_elem(t_link *link);
void				t_lst_free_tab(t_lst **lst);
void				t_lst_free_elem(t_lst *lst);
void				t_path_free_list(t_box *box);
void				t_path_free_tab(t_path **tab_path);
void				t_path_free_elem(t_path *elem_path);
void				t_room_free_tab(t_room **room);
void				t_room_free_elem(t_room *room);
void				ft_free_before_quit(t_box *box);
void				ft_free_last(t_box *box);
/*
**-----------------------------------   free end   ---------------------
*/

/*
**-----------------------------------   utils start    ---------------------
*/
t_id				calc(t_box *box);
void				index_link(t_box *box, t_id index);
void				delete_room_link(t_box *box, t_id index);
void				erase_link(t_link *link, t_id id_link, t_box *box);
t_id				ft_nbr_word(const char *s, char c);
void				chose_group(t_box *box);
void				ft_room_or_node(t_box *box, t_id id, t_id n);
void				t_room_reset_flag(t_box *box);
t_id				ft_max_group_path(t_box *box);
void				print_lst_instruction(t_instruction *instruction,
								t_id size);
/*
**-----------------------------------   utils end   ---------------------
*/

#endif
