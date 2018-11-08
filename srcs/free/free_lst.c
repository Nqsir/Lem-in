/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_lst.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/27 19:33:09 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		t_lst_free_elem(t_lst *lst)
{
	free(lst->lst);
	free(lst);
}

void		t_lst_free_tab(t_lst **lst)
{
	t_id	i;

	i = 0;
	while (lst[i])
	{
		t_lst_free_elem(lst[i]);
		i++;
	}
	free(lst);
}
