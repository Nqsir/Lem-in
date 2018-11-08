/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_bin.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 10:54:13 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		ft_free_bin(t_lst **bin_start, t_lst **bin_tmp)
{
	t_lst_free_tab(bin_start);
	t_lst_free_tab(bin_tmp);
}
