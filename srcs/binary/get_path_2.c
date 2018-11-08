/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_path_2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 18:40:23 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:39 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void		get_stop(t_group_path *group_path)
{
	t_id	i;
	t_id	j;

	i = group_path->nb_path;
	while (i > 0)
	{
		group_path->rep_path[i - 1]->stop_send = i *
									group_path->rep_path[i - 1]->value;
		j = i;
		while (j > 0)
		{
			group_path->rep_path[i - 1]->stop_send -=
					group_path->rep_path[j - 1]->value;
			j--;
		}
		i--;
	}
}

static void		ft_get_cycle_2(t_box *box, t_id path_max,
									t_id total_path, t_id i)
{
	t_id	j;

	j = 0;
	while (box->g_path[i]->rep_path[j])
	{
		if (box->tab_path[box->g_path[i]->rep_path[j]->path[0]]->value >
			path_max)
			path_max =
					box->tab_path[box->g_path[i]->rep_path[j]->path[0]]->value;
		total_path +=
				box->tab_path[box->g_path[i]->rep_path[j]->path[0]]->value;
		j++;
	}
}

void			get_cycle(t_box *box)
{
	t_id	i;
	t_id	total_path;
	t_id	path_max;

	i = 1;
	while (box->g_path[i] && box->g_path[i]->tot_shots != INT_MAX)
	{
		path_max = 0;
		total_path = 0;
		ft_get_cycle_2(box, path_max, total_path, i);
		box->g_path[i]->cycle = (box->room[0]->nb_ant - ((path_max *
			box->g_path[i]->nb_path) - total_path) +
				box->g_path[i]->nb_path) / box->g_path[i]->nb_path + path_max;
		get_stop(box->g_path[i]);
		i++;
	}
}
