/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   liaison.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 12:13:20 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void		ft_liaison_2(t_box *box, t_id *j)
{
	box->link[j[1]]->path[box->link[j[1]]->nb_link]->lst[0] = j[3];
	box->link[j[1]]->path[box->link[j[1]]->nb_link]->value = 1;
	box->link[j[1]]->nb_link++;
	box->link[j[3]]->path[box->link[j[3]]->nb_link]->lst[0] = j[1];
	box->link[j[3]]->path[box->link[j[3]]->nb_link]->value = 1;
	box->link[j[3]]->nb_link++;
}

static void		ft_free_word(char **word)
{
	free(word[0]);
	free(word[1]);
	free(word);
}

static void		check_room(char *name, t_room **room, t_id *var, t_id pos)
{
	t_id	i;

	i = 0;
	while (room[i]->name || i < 2)
	{
		if (room[i]->name)
		{
			if (ft_strcmp(room[i]->name, name) == 0)
			{
				var[pos] = 1;
				var[pos + 1] = i;
			}
		}
		i++;
	}
}

static void		check_link(t_box *box, t_id *var)
{
	t_id	i;

	i = 0;
	while (box->link[var[1]]->nb_link > i)
	{
		if (box->link[var[1]]->path[i]->lst[0] == var[3])
			var[0] = 0;
		i++;
	}
	i = 0;
	while (box->link[var[3]]->nb_link > i)
	{
		if (box->link[var[3]]->path[i]->lst[0] == var[1])
			var[2] = 0;
		i++;
	}
}

t_id			liaison(char *str, t_box *box)
{
	t_id	j[4];
	char	**word;

	word = ft_strsplit(str, '-');
	ft_bzero(j, sizeof(j));
	check_room(word[0], box->room, j, 0);
	check_room(word[1], box->room, j, 2);
	if (j[0] == 0 || j[2] == 0)
	{
		ft_free_word(word);
		return (STEP_ERROR);
	}
	check_link(box, j);
	if (j[0] == 0 || j[2] == 0)
	{
		ft_free_word(word);
		return (STEP_ERROR);
	}
	ft_liaison_2(box, j);
	ft_free_word(word);
	return (STEP_2);
}
