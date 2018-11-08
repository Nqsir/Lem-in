/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clear_anthill.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 12:20:04 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_id		clear_anthill(t_box *box)
{
	t_id	i;

	i = 1;
	while (i == 1)
	{
		i = 0;
		if (clear_room(box) == 1)
			i = 1;
		else
		{
			find_road(box);
			if (clear_loop_path(box) == 1)
				i = 1;
			else if (clear_multi_path(box) == 1)
				i = 1;
		}
	}
	return (0);
}
