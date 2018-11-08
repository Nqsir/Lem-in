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

void	t_path_free_elem(t_path *elem_path)
{
	free(elem_path->path);
	if (elem_path->next != NULL)
		free(elem_path->next);
	free(elem_path);
}

void	t_path_free_tab(t_path **tab_path)
{
	t_id	i;

	i = 0;
	while (tab_path[i])
	{
		t_path_free_elem(tab_path[i]);
		i++;
	}
	free(tab_path);
}

void	t_path_free_list(t_box *box)
{
	t_path	*tmp;

	tmp = NULL;
	while (box->list_path)
	{
		tmp = box->list_path->next;
		free(box->list_path->path);
		free(box->list_path);
		box->list_path = tmp;
	}
	free(tmp);
}
