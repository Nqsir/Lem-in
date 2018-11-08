/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_road.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 12:23:22 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static t_id		write_road(t_link **link, t_id prev, t_id actu, t_lst *path)
{
	path->lst[path->value] = actu;
	path->value++;
	if (link[actu]->nb_link == 2 || actu < 2)
	{
		if (actu > 1)
		{
			if (link[actu]->path[0]->lst[0] == prev)
				write_road(link, actu, link[actu]->path[1]->lst[0], path);
			else if (link[actu]->path[1]->lst[0] == prev)
				write_road(link, actu, link[actu]->path[0]->lst[0], path);
		}
	}
	return (0);
}

t_id			find_road(t_box *box)
{
	t_id	i;
	t_id	j;

	i = 0;
	while (box->room[i]->name)
	{
		if (box->link[i]->nb_link > 2 || i < 2)
		{
			j = 0;
			while (j < box->link[i]->nb_link)
			{
				box->link[i]->path[j]->value = 0;
				write_road(box->link, i, box->link[i]->path[j]->lst[0],
						box->link[i]->path[j]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
