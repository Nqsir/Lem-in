/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   simplify.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 12:05:34 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_id		ft_nbr_word(const char *s, char c)
{
	t_id	nbr;
	t_id	flag;

	flag = 0;
	nbr = 0;
	while (*s != '\0')
	{
		if (flag == 1 && *s == c)
			flag = 0;
		if (flag == 0 && *s != c)
		{
			flag = 1;
			nbr++;
		}
		s++;
	}
	return (nbr);
}

void		erase_link(t_link *link, t_id id_link, t_box *box)
{
	t_id	i;

	i = 0;
	while (link->path[i]->lst[0] != id_link)
		i++;
	t_lst_free_elem(link->path[i]);
	while (i < link->nb_link)
	{
		link->path[i] = link->path[i + 1];
		i++;
	}
	link->path[i] = t_lst_create_elem(box->nb_room, 0);
	link->nb_link--;
}

void		delete_room_link(t_box *box, t_id index)
{
	t_room_free_elem(box->room[index]);
	t_link_free_elem(box->link[index]);
	while (box->room[index + 1]->name)
	{
		box->room[index] = box->room[index + 1];
		box->link[index] = box->link[index + 1];
		index++;
	}
	box->room[index] = t_room_create_elem();
	box->link[index] = t_link_create_elem(box->nb_link, box->nb_room, 0);
	box->nb_room--;
}

void		index_link(t_box *box, t_id index)
{
	t_id	i;
	t_id	j;

	i = 0;
	while (box->room[i]->name)
	{
		j = 0;
		while (j < box->link[i]->nb_link)
		{
			if (box->link[i]->path[j]->lst[0] >= index)
				box->link[i]->path[j]->lst[0]--;
			j++;
		}
		i++;
	}
}
