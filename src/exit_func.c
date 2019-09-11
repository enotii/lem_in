/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:46:57 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/11 15:19:36 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	exit_func(t_map *map, int error)
{
	int i;

	free(map->links);
	free(map->ants_str);
	free(map->rooms_list);
	if (map->init_2)
	{
		free(map->path);
		free_array(map->rooms, map, 0);
		i = -1;
		while (++i < map->q_rooms)
			free(map->tab[i]);
		free(map->tab);
	}
	free(map);
	if (error)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}
