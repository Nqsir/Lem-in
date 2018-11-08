/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   last_free.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/28 19:24:45 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		ft_free_last(t_box *box)
{
	t_path_free_list(box);
	t_path_free_tab(box->tab_path);
	t_group_path_free_tab(box->g_path);
}

void		ft_free_before_quit(t_box *box)
{
	t_instruction_free_list(box);
	t_link_free_tab(box->link);
	t_room_free_tab(box->room);
	t_box_free(box);
}
