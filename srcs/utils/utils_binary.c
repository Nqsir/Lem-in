/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_binary.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 18:36:13 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_id		ft_max_group_path(t_box *box)
{
	t_id	rep;

	rep = box->room[0]->nb_ant;
	if (box->link[START]->nb_link < rep)
		rep = box->link[START]->nb_link;
	if (box->link[END]->nb_link < rep)
		rep = box->link[END]->nb_link;
	return (rep);
}

void		t_room_reset_flag(t_box *box)
{
	t_id	i;

	i = 0;
	while (box->room[i])
	{
		box->room[i]->flag = 0;
		i++;
	}
}

void		ft_room_or_node(t_box *box, t_id id, t_id n)
{
	if (box->r_or_n == NODE)
		box->l = box->link[id]->path[n]->value - 1;
	else
		box->l = ROOM;
}
