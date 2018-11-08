/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_group_path.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 14:23:46 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		t_group_path_free_elem(t_group_path *group_path)
{
	t_path_free_tab(group_path->rep_path);
	free(group_path);
}

void		t_group_path_free_tab(t_group_path **group_path)
{
	t_id	i;

	i = 0;
	while (group_path[i])
	{
		t_group_path_free_elem(group_path[i]);
		i++;
	}
	free(group_path);
}
