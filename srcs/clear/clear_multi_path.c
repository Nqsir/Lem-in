/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clear_multi_path.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 12:21:29 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static t_id		multi_path(t_box *b, t_id id_r, t_id *id_l, t_id *i)
{
	if (b->link[id_r]->path[*id_l]->lst[b->link[id_r]->path[*id_l]->value - 1]
		== b->link[id_r]->path[*i]->lst[b->link[id_r]->path[*i]->value - 1]
		&& b->link[id_r]->path[*id_l]->lst[b->link[id_r]->path[*id_l]
													->value - 1] > 1)
	{
		if (b->link[id_r]->path[*id_l]->value >= b->link[id_r]->path[*i]->value)
		{
			erase_link(b->link[b->link[id_r]->path[*id_l]->lst[0]], id_r, b);
			erase_link(b->link[id_r], b->link[id_r]->path[*id_l]->lst[0], b);
		}
		else if (b->link[id_r]->path[*id_l]->value <
				b->link[id_r]->path[*i]->value)
		{
			erase_link(b->link[b->link[id_r]->path[*i]->lst[0]], id_r, b);
			erase_link(b->link[id_r], b->link[id_r]->path[*i]->lst[0], b);
		}
		*id_l = 0;
		*i = *id_l + 1;
		return (1);
	}
	else
		*i += 1;
	return (0);
}

t_id			clear_multi_path(t_box *box)
{
	t_id	id_room;
	t_id	id_link;
	t_id	i;
	t_id	ret;

	id_room = 0;
	ret = 0;
	while (box->room[id_room]->name)
	{
		id_link = 0;
		while (id_link < box->link[id_room]->nb_link)
		{
			i = id_link + 1;
			while (i < box->link[id_room]->nb_link)
			{
				if (multi_path(box, id_room, &id_link, &i))
					ret = 1;
			}
			id_link++;
		}
		id_room++;
	}
	return (ret);
}
