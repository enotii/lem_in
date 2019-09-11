/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:47:08 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/11 15:20:32 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	check_start_end(t_map *map, char **r, int end)
{
	if (end)
	{
		map->rooms[map->q_rooms - 1] = ft_strdup(r[0]);
		(map->good[1])++;
		return ;
	}
	map->rooms[0] = ft_strdup(r[0]);
	(map->good[0])++;
}

static void	good(t_map *map, char **line, char **r, int end)
{
	if (++(map->good[end]) > 1)
	{
		free_array(r, map, 0);
		free_array(line, map, 1);
	}
}

static void	is_valid(t_map *map, int i, char **r)
{
	int r_index;

	r_index = room_index(map, r[0], 0);
	if (r_index > 0 && i != r_index)
		exit_func(map, 1);
	map->rooms[i] = ft_strdup(r[0]);
}

void		add_rooms(t_map *map)
{
	int		i;
	int		j;
	char	**line;
	char	**r;

	i = -1;
	j = 1;
	line = ft_strsplit(map->rooms_list, '\n');
	while (line[++i] && j < map->q_rooms)
	{
		r = ft_strsplit(line[i], ' ');
		if (!ft_strcmp("##start", line[i]))
			good(map, line, r, 0);
		else if (!ft_strcmp("##end", line[i]))
			good(map, line, r, 1);
		else if (map->good[0] == 1 && line[i][0] != '#')
			check_start_end(map, r, 0);
		else if (map->good[1] == 1 && line[i][0] != '#')
			check_start_end(map, r, 1);
		else if (line[i][0] != '#')
			is_valid(map, j++, r);
		free_array(r, map, 0);
	}
	free_array(line, map, 0);
}
