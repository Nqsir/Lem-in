/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   start_bin.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 20:13:33 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static int		ft_flag_path(t_box *box, t_lst **bin, t_lst **bin_tmp)
{
	t_id	n;

	n = 0;
	while (n < box->link[box->s_or_e]->nb_link)
	{
		if (!ft_init_tab_bin(box, bin, n))
		{
			if (ft_raise_flags(box, bin, bin_tmp) > 0)
			{
				ft_room_or_node(box, box->s_or_e, n);
				get_path(box, box->f);
				t_room_reset_flag(box);
				ft_set_tab_at_0(box, bin, bin_tmp);
			}
		}
		n++;
	}
	return (box->size_list_path > 0 ? 0 : -1);
}

int				ft_bin_lem_in(t_box *box)
{
	t_lst	**bin_start;
	t_lst	**bin_tmp;

	ft_init_for_bin(box);
	bin_start = t_lst_create_tab(2, box->nb_int, 0);
	bin_tmp = t_lst_create_tab(1, box->nb_int, 0);
	box->s_or_e = START;
	box->r_or_n = ROOM;
	if (ft_flag_path(box, bin_start, bin_tmp) < 0)
		return (-1);
	box->s_or_e = START;
	box->r_or_n = NODE;
	if (ft_flag_path(box, bin_start, bin_tmp) < 0)
		return (-1);
	box->s_or_e = END;
	box->r_or_n = ROOM;
	if (ft_flag_path(box, bin_start, bin_tmp) < 0)
		return (-1);
	box->s_or_e = END;
	box->r_or_n = NODE;
	if (ft_flag_path(box, bin_start, bin_tmp) < 0)
		return (-1);
	ft_free_bin(bin_start, bin_tmp);
	return (0);
}
