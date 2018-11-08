/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_path.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/29 14:36:34 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void		rec_path_2(t_box *box, t_id id_room, t_id index, t_id i)
{
	t_id	j;

	if (box->r_or_n == NODE)
	{
		j = 0;
		while (j < box->link[id_room]->path[i]->value)
		{
			box->tmp_path->path[box->tmp_path->value] =
					box->link[id_room]->path[i]->lst[j];
			box->tmp_path->value++;
			j++;
		}
	}
	else
	{
		box->tmp_path->path[box->tmp_path->value] =
				box->link[id_room]->path[i]->lst[index];
		box->tmp_path->value++;
	}
}

static void		rec_path(t_box *box, t_id id_room, t_id strat)
{
	t_id	i;
	t_id	index;

	i = 0;
	if (strat < 2)
		return ;
	while (i < box->link[id_room]->nb_link)
	{
		box->r_or_n == ROOM ? (index = 0) :
		(index = box->link[id_room]->path[i]->value - 1);
		if (box->room[box->link[id_room]->path[i]->lst[index]]->flag ==
				strat - 1)
		{
			rec_path_2(box, id_room, index, i);
			rec_path(box, box->link[id_room]->path[i]->lst[index], strat - 1);
			break ;
		}
		i++;
	}
}

static void		rev_path(t_box *box)
{
	t_id	i;
	t_id	j;
	t_id	tmp;

	i = 0;
	j = box->tmp_path->value - 1;
	while (i < j)
	{
		tmp = box->tmp_path->path[j];
		box->tmp_path->path[j] = box->tmp_path->path[i];
		box->tmp_path->path[i] = tmp;
		i++;
		j--;
	}
}

void			get_path(t_box *box, t_id value)
{
	t_id		pos;
	static int	nb = 0;

	box->size_list_path++;
	if (box->list_path == NULL)
	{
		box->list_path = t_path_create_elem(box->nb_room);
		box->tmp_path = box->list_path;
	}
	else
	{
		box->tmp_path->next = t_path_create_elem(box->nb_room);
		box->tmp_path = box->tmp_path->next;
	}
	nb++;
	if (box->s_or_e == START)
		pos = END;
	else
		pos = START;
	box->tmp_path->path[box->tmp_path->value] = pos;
	box->tmp_path->value++;
	rec_path(box, pos, value);
	if (box->s_or_e == END)
		rev_path(box);
}

void			t_path_lst_to_tab(t_box *box)
{
	t_id	i;
	t_path	*tmp_lst_path;

	i = 0;
	print_lst_instruction(box->instruction, box->i + 1);
	tmp_lst_path = box->list_path;
	box->tab_path = t_path_create_tab(box->size_list_path, box->nb_room);
	while (i < box->size_list_path)
	{
		ft_memcpy(box->tab_path[i]->path, tmp_lst_path->path, sizeof(t_id) *
				tmp_lst_path->value);
		box->tab_path[i]->value = tmp_lst_path->value;
		tmp_lst_path = tmp_lst_path->next;
		i++;
	}
}
