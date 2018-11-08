/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/11 11:58:40 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				main(void)
{
	t_box	*box;

	box = t_box_create();
	t_instruction_create_list(box);
	box->room = t_room_create_tab(box->nb_room + 2);
	box->link = t_link_create_tab(box->nb_room + 2,
		box->nb_link, PATH, 0);
	parser(box);
	if (checker(box))
		ft_printf("ERROR\n");
	else
	{
		clear_anthill(box);
		if (checker(box) || ft_bin_lem_in(box) < 0)
		{
			t_path_free_list(box);
			ft_free_before_quit(box);
			ft_printf("ERROR\n");
			return (EXIT_FAILURE);
		}
		t_path_lst_to_tab(box);
		ft_match_path(box);
	}
	ft_free_before_quit(box);
	return (EXIT_SUCCESS);
}
