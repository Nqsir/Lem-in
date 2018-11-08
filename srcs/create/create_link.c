/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_link.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/27 19:26:24 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_link		*t_link_create_elem(t_id nb_link, t_id size_lst, t_id value)
{
	t_link	*new_elem;

	if (!(new_elem = ft_memalloc(sizeof(t_link))))
		return (new_elem);
	if (!(new_elem->path = t_lst_create_tab(nb_link, size_lst, value)))
	{
		free(new_elem);
		return (new_elem);
	}
	return (new_elem);
}

t_link		**t_link_create_tab(t_id nb_room, t_id nb_link,
					t_id size_lst, t_id value)
{
	t_link	**new_link;
	t_id	i;

	i = 0;
	if (!(new_link = ft_memalloc(sizeof(*new_link) * (nb_room + 1))))
		return (new_link);
	while (i < nb_room)
	{
		new_link[i] = t_link_create_elem(nb_link, size_lst, value);
		i++;
	}
	return (new_link);
}
