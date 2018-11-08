/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fourmis.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 12:12:58 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_id		fourmis(char *word, t_box *box)
{
	t_id	i;

	if ((i = ft_strlen(word)) > 10)
		return (STEP_ERROR);
	box->room[0]->nb_ant = (size_t)ft_atoi(word);
	if (box->room[0]->nb_ant <= 0)
		return (STEP_ERROR);
	return (STEP_1);
}
