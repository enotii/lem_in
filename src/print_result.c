/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:46:24 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/11 15:18:50 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_ant(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

static void	print_result(t_map *map, int n)
{
	int ants;

	if (n == (map->p_ind + map->ants + 1))
		return ;
	ants = map->ants + 1;
	while (--ants > 0)
	{
		if (n - ants > 0 && (n - ants) <= map->p_ind)
			print_ant(ants, map->rooms[map->path[n - ants]]);
	}
	ft_putchar('\n');
	print_result(map, ++n);
}

void		result(t_map *map)
{
	int i;

	i = -1;
	ft_putendl(map->ants_str);
	ft_putendl(map->rooms_list);
	ft_putendl(map->links);
	ft_putchar('\n');
	while (++i <= map->p_ind)
	{
		ft_putchar('[');
		ft_putnbr(map->path[i]);
		ft_putchar(']');
		if (i != map->p_ind)
			ft_putchar('-');
	}
	ft_putstr("\n\n");
	print_result(map, 2);
}
