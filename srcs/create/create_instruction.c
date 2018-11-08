/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_box.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 12:11:21 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		t_instruction_create_list(t_box *box)
{
	char			*str;
	t_instruction	*tmp;
	int				rep;

	str = NULL;
	tmp = NULL;
	while ((rep = get_next_line(0, &str)) > 0 && str[0] != '\0')
	{
		if (box->instruction == NULL)
		{
			box->instruction = ft_memalloc(sizeof(t_instruction));
			box->instruction->str = ft_strdup(str);
			tmp = box->instruction;
		}
		else
		{
			tmp->next = ft_memalloc(sizeof(t_instruction));
			tmp = tmp->next;
			tmp->str = ft_strdup(str);
		}
		box->nb_instruction += 1;
		free(str);
	}
	(rep > -1) ? free(str) : (rep = 0);
	calc(box);
}
