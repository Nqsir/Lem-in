/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   send_ant.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 18:28:39 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void		send_ant_4(t_box *box, t_group_path *g_path,
								t_id i, t_id *name)
{
	t_id	j;
	t_id	nb_ant;

	nb_ant = box->room[0]->nb_ant;
	j = 1;
	j--;
	while (box->room[1]->nb_ant < nb_ant)
	{
		if (box->room[0]->nb_ant > 0 && box->room[0]->nb_ant >
				g_path->rep_path[i]->stop_send)
		{
			box->room[box->tab_path[g_path->rep_path[
				i]->path[0]]->path[j]]->ant_n = *name;
			*name += 1;
			box->room[box->tab_path[g_path->rep_path[
				i]->path[0]]->path[j]]->nb_ant++;
			box->room[box->tab_path[g_path->rep_path[
				i]->path[0]]->path[j + 1]]->nb_ant--;
			ft_printf("L%i-%s ", box->room[box->tab_path[g_path->rep_path[
				i]->path[0]]->path[j]]->ant_n, box->room[box->tab_path[
					g_path->rep_path[i]->path[0]]->path[j]]->name);
		}
	}
}

static void		send_ant_3(t_box *box, t_group_path *g_path,
							t_id i, t_id *j)
{
	while (g_path->tot_shots != INT_MAX && *j <
				g_path->rep_path[i]->value - 1)
	{
		if (box->room[box->tab_path[g_path->rep_path[i]->path[0]]
				->path[*j]]->nb_ant > 0)
		{
			box->room[box->tab_path[
				g_path->rep_path[i]->path[0]]->path[*j - 1]]->ant_n = box->room[
					box->tab_path[
						g_path->rep_path[i]->path[0]]->path[*j]]->ant_n;
			box->room[box->tab_path[g_path->rep_path[i]->path[0]]->path[
				*j]]->ant_n = 0;
			box->room[box->tab_path[g_path->rep_path[i]->path[0]]->path[
				*j - 1]]->nb_ant++;
			box->room[box->tab_path[g_path->rep_path[i]->path[0]]->path[
				*j]]->nb_ant = 0;
			ft_printf("L%i-%s ", box->room[box->tab_path[
				g_path->rep_path[i]->path[0]]->path[*j - 1]]->ant_n, box->room[
					box->tab_path[g_path->rep_path[i]->path[0]]->path[
						*j - 1]]->name);
		}
		*j += 1;
	}
}

static void		send_ant_2(t_box *box, t_group_path *g_path,
							t_id i, t_id *name)
{
	t_id	j;

	j = 1;
	send_ant_3(box, g_path, i, &j);
	j--;
	if (g_path->rep_path[i]->value == 2)
		send_ant_4(box, g_path, i, name);
	else
	{
		if (box->room[0]->nb_ant > 0 && box->room[0]->nb_ant >
				g_path->rep_path[i]->stop_send)
		{
			box->room[box->tab_path[g_path->rep_path[
				i]->path[0]]->path[j]]->ant_n = *name;
			*name += 1;
			box->room[box->tab_path[g_path->rep_path[
				i]->path[0]]->path[j]]->nb_ant++;
			box->room[box->tab_path[g_path->rep_path[
				i]->path[0]]->path[j + 1]]->nb_ant--;
			ft_printf("L%i-%s ", box->room[box->tab_path[g_path->rep_path[
				i]->path[0]]->path[j]]->ant_n, box->room[box->tab_path[
					g_path->rep_path[i]->path[0]]->path[j]]->name);
		}
	}
}

static void		send_ant_1(t_box *box, t_group_path *g_path)
{
	t_id	name;
	t_id	nb_ant;
	t_id	i;

	name = 1;
	nb_ant = box->room[0]->nb_ant;
	while (box->room[1]->nb_ant < nb_ant)
	{
		i = 0;
		while (i < g_path->nb_path)
		{
			send_ant_2(box, g_path, i, &name);
			i++;
		}
		ft_printf("\n");
	}
}

void			chose_group(t_box *box)
{
	size_t			tmp;
	size_t			i;
	t_group_path	*tmp_group;

	i = 1;
	tmp = box->g_path[i]->cycle;
	tmp_group = box->g_path[i];
	while (box->g_path[i])
	{
		if (box->g_path[i]->cycle < tmp
			&& box->g_path[i]->tot_shots < 2147483647)
		{
			tmp = box->g_path[i]->cycle;
			tmp_group = box->g_path[i];
		}
		i++;
	}
	send_ant_1(box, tmp_group);
}
