/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   commande.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 12:12:15 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 17:23:38 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void		ft_commande_2(t_box *box, t_id *status, t_id type)
{
	t_id		nb_word[2];

	if (box->tmp)
	{
		box->tmp = box->tmp->next;
		nb_word[0] = ft_nbr_word(box->tmp->str, ' ');
		if (nb_word[0] == 3 && box->tmp->str[0] != 'L')
			*status = salle(box, type);
		else
			*status = STEP_ERROR;
	}
	else
		*status = STEP_ERROR;
}

static t_id		def_type(t_box *box)
{
	if (ft_strcmp(box->tmp->str, "##start") == 0)
		return (1);
	else if (ft_strcmp(box->tmp->str, "##end") == 0)
		return (2);
	else
		return (0);
}

t_id			commande(t_box *box, t_id step)
{
	t_id		status;
	t_id		type;

	status = step;
	if ((type = def_type(box)) == 0)
		return (status);
	if ((box->room[0]->name && type == 1) || (box->room[1]->name && type == 2))
		return (STEP_ERROR);
	while (box->tmp && box->tmp->next->str[0] == '#')
	{
		if (box->tmp && box->tmp->next->str[0] == '#'
			&& box->tmp->next->str[1] == '#')
		{
			if (box->tmp->next &&
				(ft_strcmp(box->tmp->next->str, "##start") == 0 ||
					ft_strcmp(box->tmp->next->str, "##end") == 0))
				return (STEP_ERROR);
		}
		box->tmp = box->tmp->next;
	}
	ft_commande_2(box, &status, type);
	return (status);
}
