/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_path.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/28 19:15:14 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_path		*t_path_create_elem(size_t size_path)
{
	t_path	*new_elem;

	if (!(new_elem = ft_memalloc(sizeof(t_path))))
		return (new_elem);
	if (!(new_elem->path = ft_memalloc(sizeof(size_t) * size_path)))
	{
		free(new_elem);
		return (new_elem);
	}
	return (new_elem);
}

t_path		**t_path_create_tab(size_t nb_path, size_t size_path)
{
	t_path	**new_tab;
	t_id	i;

	i = 0;
	if (!(new_tab = ft_memalloc(sizeof(*new_tab) * (nb_path + 1))))
		return (new_tab);
	while (i < nb_path)
	{
		new_tab[i] = t_path_create_elem(size_path);
		i++;
	}
	return (new_tab);
}
