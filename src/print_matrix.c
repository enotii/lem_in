/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 00:51:20 by ashulha           #+#    #+#             */
/*   Updated: 2019/09/10 19:51:25 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	header(t_map *m)
{
	int i;

	i = -1;
	ft_putstr("\n\n");
	ft_putstr("\t   ");
	while (++i < m->q_rooms)
	{
		ft_putchar(' ');
		ft_putnbr((i > 9) ? (i % 10) : i);
	}
	ft_putstr("\n\n");
}

void		print_matrix(t_map *m)
{
	int i;
	int j;

	header(m);
	i = -1;
	while (++i < m->q_rooms)
	{
		ft_putchar('\t');
		ft_putnbr((i > 9) ? (i % 10) : i);
		ft_putstr("   ");
		j = -1;
		while (++j < m->q_rooms)
		{
			ft_putnbr(m->tab[i][j]);
			ft_putchar(' ');
		}
		ft_putstr("\t\t");
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("] -  ");
		ft_putendl(m->rooms[i]);
	}
	ft_putstr("\n\n");
}
