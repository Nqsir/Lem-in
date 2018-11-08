/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clear_loop_path.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 12:20:44 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_id		clear_loop_path(t_box *b)
{
	t_id		i;
	t_id		j;
	t_id		ret;

	i = 0;
	ret = 0;
	while (b->room[i]->name)
	{
		j = 0;
		while (j < b->link[i]->nb_link)
		{
			if (b->link[i]->path[j]->lst[b->link[i]->path[j]->value - 1] == i)
			{
				ret = 1;
				erase_link(b->link[b->link[i]->path[j]->lst[0]], i, b);
				erase_link(b->link[i], b->link[i]->path[j]->lst[0], b);
				j = 0;
			}
			else
				j++;
		}
		i++;
	}
	return (ret);
}
