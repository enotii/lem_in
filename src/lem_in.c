/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 19:55:10 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/11 15:20:46 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		is_empty(char *s)
{
	size_t i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

static t_map	*map_init_2(t_map *map)
{
	int i;
	int j;

	i = -1;
	map->init_2 = 1;
	map->path = (int*)ft_memalloc(sizeof(int) * 1000);
	map->tab = (int**)ft_memalloc(sizeof(int*) * map->q_rooms);
	map->rooms = (char**)ft_memalloc(sizeof(char*) * (map->q_rooms + 1));
	while (++i < map->q_rooms)
	{
		map->path[i] = -1;
		map->rooms[i] = NULL;
		map->tab[i] = (int*)ft_memalloc(sizeof(int) * map->q_rooms);
		j = -1;
		while (map->tab[i][++j])
			map->tab[i][j] = 0;
	}
	map->rooms[i] = NULL;
	map->path[0] = 0;
	return (map);
}

static void		read_map(t_map *map)
{
	char *line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (map->ants == 0)
			count_ants(map, line);
		else if (ft_strchr(line, '-') || map->started == 3)
			links(map, line);
		else if ((map->started == 1 || map->started == 2) && !is_empty(line))
			rooms(map, line);
		else
			exit_func(map, 1);
	}
	if (!map->ants || !map->links[0])
		exit_func(map, 1);
	map = map_init_2(map);
}

static t_map	*map_init(void)
{
	t_map *map;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->links = ft_strnew(1);
	map->ants_str = ft_strnew(1);
	map->rooms_list = ft_strnew(1);
	map->q_rooms = 0;
	map->ants = 0;
	map->started = 0;
	map->curr_room = 0;
	map->p_ind = 0;
	map->init_2 = 0;
	map->good[0] = 0;
	map->good[1] = 0;
	map->rooms = NULL;
	map->tab = NULL;
	map->path = NULL;
	return (map);
}

int				main(void)
{
	t_map *map;

	map = map_init();
	read_map(map);
	add_rooms(map);
	if (!map->good[0] || !map->good[1])
		exit_func(map, 1);
	create_tab(map);
	print_matrix(map);
	if (solution(map, 0))
		result(map);
	else
		exit_func(map, 1);
	exit_func(map, 0);
}
