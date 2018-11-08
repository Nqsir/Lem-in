/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   match_path.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 18:18:33 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_id		ft_comp_tab_bin(t_box *box, t_lst **tab,
					t_id id_path, t_id strat)
{
	t_id		i;
	t_id		n;
	t_id		*tmp;

	i = id_path + 1;
	tmp = ft_merge_lines_tab_bin(box, tab, id_path, strat);
	while (i < box->size_list_path)
	{
		n = 0;
		while (n < box->nb_int)
		{
			if ((tmp[n] & tab[i]->lst[n]) != 0)
				break ;
			n++;
		}
		if (n == box->nb_int)
		{
			free(tmp);
			return (i);
		}
		i++;
	}
	free(tmp);
	return (0);
}

static void		ft_init_if_strat(t_box *box, t_lst **tab, t_id strat, t_id i)
{
	box->g_path[0]->tot_shots += tab[i]->value;
	box->g_path[0]->rep_path[strat]->value = tab[i]->value;
}

static void		ft_init_if_strat_0(t_box *box, t_lst **tab, t_id strat, t_id i)
{
	box->g_path[0]->rep_path[strat]->value = tab[i]->value;
	box->g_path[0]->tot_shots = tab[i]->value;
	box->g_path[0]->nb_path = 1;
}

static void		ft_make_path_bin(t_box *box, t_lst **tab,
					t_id id_path, t_id strat)
{
	t_id	i;
	t_id	next_id;

	i = id_path;
	while (i < box->size_list_path)
	{
		box->g_path[0]->rep_path[strat]->path[0] = i;
		next_id = ft_comp_tab_bin(box, tab, i, strat);
		if (strat == 0)
			ft_init_if_strat_0(box, tab, strat, i);
		else
			ft_init_if_strat(box, tab, strat, i);
		if (box->g_path[0]->tot_shots < box->g_path[strat + 1]->tot_shots)
			ft_cpy_path_bin(box, strat + 1);
		if (next_id != 0 && strat < (box->nb_strat - 1))
			ft_make_path_bin(box, tab, next_id, strat + 1);
		if (strat == (box->nb_strat - 1))
		{
			box->g_path[0]->tot_shots -= tab[i]->value;
			box->g_path[0]->rep_path[strat]->path[0] = 0;
			return ;
		}
		box->g_path[0]->rep_path[strat]->path[0] = 0;
		i++;
	}
}

void			ft_match_path(t_box *box)
{
	t_lst			**tab;

	box->nb_strat = ft_max_group_path(box);
	tab = t_lst_create_tab((box->size_list_path + 1), box->nb_int, 0);
	box->g_path = t_group_path_create_tab(box->nb_strat + 1, 2);
	ft_sort_tab_bin(box);
	ft_swap_to_bin(box, tab);
	ft_make_path_bin(box, tab, 0, 0);
	get_cycle(box);
	t_lst_free_tab(tab);
	chose_group(box);
	ft_free_last(box);
}
