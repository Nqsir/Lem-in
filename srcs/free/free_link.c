/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_link.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/27 19:25:21 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		t_link_free_elem(t_link *link)
{
	t_lst_free_tab(link->path);
	free(link);
}

void		t_link_free_tab(t_link **link)
{
	t_id	i;

	i = 0;
	while (link[i])
	{
		t_link_free_elem(link[i]);
		i++;
	}
	free(link);
}
