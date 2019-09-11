/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:46:34 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/11 15:02:41 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	header(t_map *map)
{
	int i;

	i = -1;
	ft_putstr("\n\n");
	ft_putstr("\t   ");
	while (++i < map->q_rooms)
	{
		ft_putchar(' ');
		ft_putnbr((i > 9) ? (i % 10) : i);
	}
	ft_putstr("\n\n");
}

void		print_matrix(t_map *map)
{
	int i;
	int j;

	header(map);
	i = -1;
	while (++i < map->q_rooms)
	{
		ft_putchar('\t');
		ft_putnbr((i > 9) ? (i % 10) : i);
		ft_putstr("   ");
		j = -1;
		while (++j < map->q_rooms)
		{
			ft_putnbr(map->tab[i][j]);
			ft_putchar(' ');
		}
		ft_putstr("\t\t");
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("] -  ");
		ft_putendl(map->rooms[i]);
	}
	ft_putstr("\n\n");
}
