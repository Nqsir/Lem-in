/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_instruction.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/27 19:32:34 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	t_instruction_free_list(t_box *box)
{
	t_instruction	*tmp;

	tmp = NULL;
	while (box->instruction)
	{
		tmp = box->instruction->next;
		free(box->instruction->str);
		free(box->instruction);
		box->instruction = tmp;
	}
	free(tmp);
}
