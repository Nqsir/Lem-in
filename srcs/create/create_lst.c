/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_path.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 12:07:02 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_lst		*t_lst_create_elem(t_id size_list, t_id value)
{
	t_lst	*new_elem;

	if (!(new_elem = ft_memalloc(sizeof(t_lst))))
		return (new_elem);
	if (!(new_elem->lst = ft_memalloc(sizeof(t_id) * size_list)))
	{
		free(new_elem);
		return (new_elem);
	}
	new_elem->value = value;
	return (new_elem);
}

t_lst		**t_lst_create_tab(t_id nb_list, t_id size_list, t_id value)
{
	t_lst	**new_lst;
	t_id	i;

	i = 0;
	if (!(new_lst = ft_memalloc(sizeof(*new_lst) * (nb_list + 1))))
		return (new_lst);
	while (i < nb_list)
	{
		new_lst[i] = t_lst_create_elem(size_list, value);
		i++;
	}
	return (new_lst);
}
