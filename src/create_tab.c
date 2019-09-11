/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:47:01 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/11 15:19:53 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	validate_link(t_map *map, char *link)
{
	char **l;

	l = ft_strsplit(link, '-');
	if (l[2] != NULL)
		free_array(l, map, 1);
	free_array(l, map, 0);
}

void		create_tab(t_map *map)
{
	int		i;
	int		r_1;
	int		r_2;
	char	**l;
	char	**links;

	i = -1;
	links = ft_strsplit(map->links, '\n');
	while (links[++i])
	{
		if (links[i][0] == '#')
			continue ;
		validate_link(map, links[i]);
		l = ft_strsplit(links[i], '-');
		if ((r_1 = room_index(map, l[0], 1)) >= map->q_rooms ||
			(r_2 = room_index(map, l[1], 1)) >= map->q_rooms)
		{
			free_array(l, map, 0);
			free_array(links, map, 1);
		}
		(r_2) ? (map->tab[r_1][r_2] = 1) : 0;
		(r_1) ? (map->tab[r_2][r_1] = 1) : 0;
		free_array(l, map, 0);
	}
	free_array(links, map, 0);
}
