/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clear_room.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 12:22:31 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void		raz_size_path(t_box *box)
{
	t_id		i;
	t_id		j;
	t_id		tmp;

	i = 0;
	while (box->room[i]->name)
	{
		j = 0;
		while (j < box->link[i]->nb_link)
		{
			box->link[i]->path[j]->value = 1;
			tmp = box->link[i]->path[j]->lst[0];
			ft_bzero(box->link[i]->path[j]->lst, box->nb_room);
			box->link[i]->path[j]->lst[0] = tmp;
			j++;
		}
		i++;
	}
}

t_id			clear_room(t_box *box)
{
	t_id		i;
	t_id		ret;

	i = 2;
	ret = 0;
	raz_size_path(box);
	while (box->room[i]->name)
	{
		if (box->link[i]->nb_link == 0 || box->link[i]->nb_link == 1)
		{
			ret = 1;
			if (box->link[i]->nb_link == 1)
				erase_link(box->link[box->link[i]->path[0]->lst[0]], i, box);
			delete_room_link(box, i);
			index_link(box, i);
			i = 2;
		}
		else
			i++;
	}
	return (ret);
}
