/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_room.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/27 19:52:57 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_room		*t_room_create_elem(void)
{
	t_room	*new_elem;

	new_elem = ft_memalloc(sizeof(t_room));
	return (new_elem);
}

t_room		**t_room_create_tab(t_id nb_room)
{
	t_room	**new_tab;
	t_id	i;

	i = 0;
	if (!(new_tab = ft_memalloc(sizeof(*new_tab) * (nb_room + 1))))
		return (new_tab);
	while (i < nb_room)
	{
		new_tab[i] = t_room_create_elem();
		i++;
	}
	return (new_tab);
}
