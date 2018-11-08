/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_room.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/27 19:29:35 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		t_room_free_elem(t_room *room)
{
	if (room->name != NULL)
		free(room->name);
	free(room);
}

void		t_room_free_tab(t_room **room)
{
	t_id	i;

	i = 0;
	while (room[i])
	{
		t_room_free_elem(room[i]);
		i++;
	}
	free(room);
}
