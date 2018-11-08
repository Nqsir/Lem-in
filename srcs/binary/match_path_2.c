/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   match_path_2.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 18:19:04 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void			ft_sort_tab_bin(t_box *box)
{
	int		i;
	t_path	*tmp_tab;

	i = 0;
	while ((t_id)i < (box->size_list_path - 1))
	{
		if (box->tab_path[i + 1] && box->tab_path[i + 1]->value <
			box->tab_path[i]->value && box->tab_path[i]->value > 0)
		{
			tmp_tab = box->tab_path[i + 1];
			box->tab_path[i + 1] = box->tab_path[i];
			box->tab_path[i] = tmp_tab;
			i = -1;
		}
		i++;
	}
}

void			ft_swap_to_bin(t_box *box, t_lst **tab)
{
	t_id	i;
	t_id	n;

	i = 0;
	while (i < box->size_list_path)
	{
		n = 1;
		tab[i]->value = box->tab_path[i]->value;
		while (n < (box->tab_path[i]->value - 1))
		{
			tab[i]->lst[box->tab_path[i]->path[n] / 32] |=
					1 << (box->tab_path[i]->path[n] & 31);
			n++;
		}
		i++;
	}
}

void			ft_cpy_path_bin(t_box *box, t_id strat)
{
	t_id	i;

	i = 0;
	box->g_path[strat]->tot_shots = box->g_path[0]->tot_shots;
	while (i < strat)
	{
		box->g_path[strat]->rep_path[i]->path[0] =
				box->g_path[0]->rep_path[i]->path[0];
		box->g_path[strat]->rep_path[i]->value =
				box->g_path[0]->rep_path[i]->value;
		i++;
	}
}

static void		ft_merge_if_strat_0(t_box *box, t_lst **tab,
					t_id **new, t_id id)
{
	t_id	n;

	n = 0;
	while (n < box->nb_int)
	{
		(*new)[n] = (tab[id]->lst[n] |
			tab[box->g_path[0]->rep_path[0]->path[0]]->lst[n]);
		n++;
	}
}

t_id			*ft_merge_lines_tab_bin(t_box *box, t_lst **tab,
										t_id id, t_id strat)
{
	t_id	i;
	t_id	n;
	t_id	*new;

	i = 0;
	if (!(new = ft_memalloc(sizeof(t_id) * box->nb_int)))
		return (0);
	if (strat == 0)
		ft_merge_if_strat_0(box, tab, &new, id);
	else
	{
		while (i < strat)
		{
			n = 0;
			while (n < box->nb_int)
			{
				new[n] |= (tab[id]->lst[n] |
						tab[box->g_path[0]->rep_path[i]->path[0]]->lst[n]);
				n++;
			}
			i++;
		}
	}
	return (new);
}
