/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   write_flags_bin.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 20:13:43 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static int		ft_get_out_flags(t_box *box, t_lst **bin, t_lst **tmp)
{
	t_id		n;

	n = 0;
	if ((box->s_or_e == 0 && (bin[0]->lst[0] & 1 << 1) > 0)
		|| (box->s_or_e == 1 && (bin[0]->lst[0] & 1 << 0) > 0))
		return (1);
	while (n < (box->nb_int - 1))
	{
		if (tmp[0]->lst[n] > 0)
			break ;
		n++;
	}
	if ((n == box->nb_int - 1) && (tmp[0]->lst[n] == 0))
		return (-1);
	return (0);
}

static int		ft_id_bits(t_box *box, t_lst **tmp)
{
	static t_id		i = 0;
	static t_id		n = 0;
	static int		nbr = -1;

	while (i < box->nb_int)
	{
		while (n < 32)
		{
			nbr++;
			if ((tmp[0]->lst[i] & 1 << n) > 0)
			{
				n++;
				return (nbr);
			}
			n++;
		}
		i++;
		n = 0;
	}
	nbr = -1;
	i = 0;
	n = 0;
	return (-1);
}

static int		ft_check_if_finish(t_box *box, t_lst **bin)
{
	t_id	i;
	t_id	last;

	i = 0;
	last = 0;
	last = ~(~(last) << (box->nb_room & 31));
	while (i < box->nb_int)
	{
		if ((i != box->nb_int - 1) && (bin[0]->lst[i] != ULONG_MAX))
			return (1);
		else if ((i == box->nb_int - 1) && (bin[0]->lst[i] != last))
			return (1);
		i++;
	}
	return (0);
}

static void		ft_raise_id_flags(t_box *box, t_lst **bin, int id)
{
	t_id	n;

	n = 0;
	while (n < box->link[id]->nb_link)
	{
		ft_room_or_node(box, id, n);
		if (box->room[box->link[id]->path[n]->lst[box->l]]->flag == 0)
		{
			bin[0]->lst[box->link[id]->path[n]->lst[box->l] / 32] |=
					1 << (box->link[id]->path[n]->lst[box->l] & 31);
			box->room[box->link[id]->path[n]->lst[box->l]]->flag = box->f;
		}
		n++;
	}
}

int				ft_raise_flags(t_box *box, t_lst **bin, t_lst **tmp)
{
	int		check;
	int		id;

	box->f = 2;
	if (box->nb_room == 2)
		return (1);
	while (ft_check_if_finish(box, bin))
	{
		box->f++;
		ft_init_tmp(box, bin, tmp);
		ft_init_tab_1(box, bin);
		while ((id = ft_id_bits(box, tmp)) >= 0)
			ft_raise_id_flags(box, bin, id);
		check = ft_get_out_flags(box, bin, tmp);
		if (check == 1)
			return (1);
		else if (check == -1)
			return (-1);
	}
	return (0);
}
