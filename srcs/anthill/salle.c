/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   salle.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 12:16:15 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void		fill_room(t_room **room, char **word, t_id i, t_id type)
{
	if (type == 1)
		i = 0;
	else if (type == 2)
		i = 1;
	room[i]->name = ft_strdup(word[0]);
	room[i]->x = (size_t)ft_atoi(word[1]);
	room[i]->y = (size_t)ft_atoi(word[2]);
	free(word[0]);
	free(word[1]);
	free(word[2]);
	free(word);
}

t_id			salle(t_box *box, t_id type)
{
	t_id	i;
	char	**word;

	i = 0;
	word = ft_strsplit(box->tmp->str, ' ');
	if (!ft_strisdigit(word[1]) || !ft_strisdigit(word[2])
		|| ft_strlen(word[1]) > 10 || ft_strlen(word[2]) > 10
		|| (ft_strchr(word[0], '-') != NULL))
		return (STEP_ERROR);
	while (box->room[i]->name || i < 2)
	{
		if ((i < 2 && box->room[i]->name) || i >= 2)
		{
			if (ft_strcmp(box->room[i]->name, word[0]) == 0
				|| ((long)box->room[i]->x == ft_atoi(word[1])
				&& (long)box->room[i]->y == ft_atoi(word[2])))
				return (STEP_ERROR);
		}
		i++;
	}
	fill_room(box->room, word, i, type);
	box->test_room = 1;
	return (STEP_1);
}
