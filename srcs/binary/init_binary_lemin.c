/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_binary_lemin.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/28 19:36:42 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		ft_init_for_bin(t_box *box)
{
	box->nb_int = box->nb_room / 32;
	if ((box->nb_room % 32) != 0)
		box->nb_int += 1;
}

void		ft_init_tab_1(t_box *box, t_lst **bin)
{
	t_id	i;

	i = 0;
	while (i < box->nb_int)
	{
		bin[1]->lst[i] = bin[0]->lst[i];
		i++;
	}
}

void		ft_init_tmp(t_box *box, t_lst **bin, t_lst **tmp)
{
	t_id	i;

	i = 0;
	while (i < box->nb_int)
	{
		tmp[0]->lst[i] = (bin[0]->lst[i] ^ bin[1]->lst[i]);
		i++;
	}
}

t_id		ft_init_tab_bin(t_box *box, t_lst **bin, t_id n)
{
	ft_room_or_node(box, box->s_or_e, n);
	bin[0]->lst[box->link[box->s_or_e]->path[n]->lst[box->l] / 32] |=
		1 << (box->link[box->s_or_e]->path[n]->lst[box->l] & 31);
	box->room[box->s_or_e]->flag = 1;
	box->room[box->link[box->s_or_e]->path[n]->lst[box->l]]->flag = 2;
	box->s_or_e == 1 ? (bin[0]->lst[0] |= 1 << 1) : (bin[0]->lst[0] |= 1 << 0);
	box->s_or_e == 1 ? (bin[1]->lst[0] |= 1 << 1) : (bin[1]->lst[0] |= 1 << 0);
	if (box->nb_room > 2 && box->link[box->s_or_e]->path[n]->lst[box->l] < 2)
	{
		box->room[box->s_or_e]->flag = 2;
		get_path(box, box->f);
		bin[0]->lst[0] = 0;
		bin[1]->lst[0] = 0;
		t_room_reset_flag(box);
		return (1);
	}
	return (0);
}

void		ft_set_tab_at_0(t_box *box, t_lst **bin_start,
								t_lst **bin_tmp)
{
	t_id		n;

	n = 0;
	while (n < box->nb_int)
	{
		bin_start[0]->lst[n] = 0;
		bin_start[1]->lst[n] = 0;
		bin_tmp[0]->lst[n] = 0;
		n++;
	}
}
