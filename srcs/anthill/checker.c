/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 12:11:54 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_id		checker(t_box *box)
{
	if (!box->room[0]->name || box->link[0]->nb_link == 0
		|| box->room[0]->nb_ant <= 0)
		return (EXIT_FAILURE);
	if (!box->room[1]->name || box->link[1]->nb_link == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
