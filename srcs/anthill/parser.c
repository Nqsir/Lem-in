/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 12:14:41 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void		ft_status_ants(t_box *box, t_id *status)
{
	if (box->tmp->str[0] == '#' && box->tmp->str[1] != '#')
		return ;
	else if (box->tmp->str[0] == '#' && box->tmp->str[1] == '#')
		*status = commande(box, *status);
	else if (ft_strisdigit(box->tmp->str))
		*status = fourmis(box->tmp->str, box);
	else
		*status = STEP_ERROR;
}

static void		ft_status_rooms(t_box *box, t_id *status)
{
	t_id			nb_word[2];

	if ((nb_word[0] = ft_nbr_word(box->tmp->str, ' ')) == 1)
		nb_word[1] = ft_nbr_word(box->tmp->str, '-');
	else
		nb_word[1] = 0;
	if (box->tmp->str[0] == '#' && box->tmp->str[1] != '#')
		return ;
	else if (box->tmp->str[0] == '#' && box->tmp->str[1] == '#')
		*status = commande(box, *status);
	else if (nb_word[0] == 1 && nb_word[1] == 2 && box->test_room > 0)
		*status = liaison(box->tmp->str, box);
	else if (nb_word[0] == 3 && box->tmp->str[0] != 'L')
		*status = salle(box, 0);
	else
		*status = STEP_ERROR;
}

static void		ft_status_links(t_box *box, t_id *status)
{
	t_id	nb_word[2];

	if ((nb_word[0] = ft_nbr_word(box->tmp->str, ' ')) == 1)
		nb_word[1] = ft_nbr_word(box->tmp->str, '-');
	else
		nb_word[1] = 0;
	if (box->tmp->str[0] == '#' && box->tmp->str[1] != '#')
		return ;
	else if (box->tmp->str[0] == '#' && box->tmp->str[1] == '#')
		*status = commande(box, *status);
	else if (nb_word[0] == 1 && nb_word[1] == 2 && box->test_room > 0)
		*status = liaison(box->tmp->str, box);
	else
		*status = STEP_ERROR;
}

t_id			parser(t_box *box)
{
	t_id	status;

	status = STEP_0;
	box->tmp = box->instruction;
	while ((box->tmp) && status < 3)
	{
		if (status == 0)
			ft_status_ants(box, &status);
		else if (status == 1)
			ft_status_rooms(box, &status);
		else if (status == 2)
			ft_status_links(box, &status);
		box->i++;
		box->tmp = box->tmp->next;
	}
	if (status != STEP_ERROR)
		box->i++;
	return (status);
}
