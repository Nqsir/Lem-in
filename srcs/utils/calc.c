/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calc.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/27 19:21:53 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static t_id		search_link(char **word)
{
	t_id	i;
	t_id	j;
	t_id	nb;
	t_id	tmp;

	i = 0;
	nb = 0;
	while (word[i])
	{
		j = i + 1;
		tmp = 1;
		while (word[j])
		{
			if (!ft_strcmp(word[i], word[j]))
				tmp++;
			j++;
		}
		if (tmp > nb)
			nb = tmp;
		i++;
	}
	return (nb + 1);
}

static void		calc_2(t_box *box, char **str)
{
	t_id	nb_word[2];
	char	*str_tmp;

	if ((nb_word[0] = ft_nbr_word(box->tmp->str, ' ')) == 1)
		nb_word[1] = ft_nbr_word(box->tmp->str, '-');
	else
		nb_word[1] = 0;
	if (nb_word[0] == 1 && nb_word[1] == 2)
	{
		box->nb_link++;
		str_tmp = ft_strjoin(*str, box->tmp->str);
		free(*str);
		*str = ft_strjoin(str_tmp, "-");
		free(str_tmp);
	}
	else if (nb_word[0] == 3 && box->tmp->str[0] != 'L')
		box->nb_room++;
	box->tmp = box->tmp->next;
}

t_id			calc(t_box *box)
{
	char	*str;
	char	**word;
	t_id	i;

	i = 0;
	str = ft_strdup("");
	box->tmp = box->instruction;
	while (box->tmp)
		calc_2(box, &str);
	word = ft_strsplit(str, '-');
	box->nb_link = search_link(word);
	while (word[i])
	{
		free(word[i]);
		i++;
	}
	free(word);
	free(str);
	box->tmp = box->instruction;
	return (0);
}
