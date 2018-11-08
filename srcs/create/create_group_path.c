/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_group_path.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 14:23:46 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_group_path		*t_group_path_create_elem(size_t nb_path, size_t size_path)
{
	t_group_path	*new_elem;

	if (!(new_elem = ft_memalloc(sizeof(t_group_path))))
		return (new_elem);
	if (!(new_elem->rep_path = t_path_create_tab(nb_path, size_path)))
	{
		free(new_elem);
		return (new_elem);
	}
	new_elem->tot_shots = INT_MAX;
	new_elem->nb_path = nb_path;
	return (new_elem);
}

t_group_path		**t_group_path_create_tab(size_t nb_group, size_t size_path)
{
	t_group_path	**new_tab;
	size_t			i;

	i = 0;
	if (!(new_tab = ft_memalloc(sizeof(*new_tab) * (nb_group + 1))))
		return (new_tab);
	new_tab[i] = t_group_path_create_elem(nb_group - 1, size_path);
	i++;
	while (i < nb_group)
	{
		new_tab[i] = t_group_path_create_elem(i, size_path);
		i++;
	}
	return (new_tab);
}
