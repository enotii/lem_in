/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:46:13 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/11 15:18:32 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	is_number(char **r, t_map *map, char *s)
{
	int i;

	i = 0;
	if (s[0] == '-' || ft_isdigit(s[0]))
	{
		while (s[++i])
		{
			if (!ft_isdigit(s[i]))
				free_array(r, map, 1);
		}
	}
	else
		free_array(r, map, 1);
}

static void	validate_room(t_map *map, char *line)
{
	char **r;

	r = ft_strsplit(line, ' ');
	if (r[0][0] == 'L' || r[3] != NULL)
		free_array(r, map, 1);
	is_number(r, map, r[1]);
	is_number(r, map, r[2]);
	free_array(r, map, 0);
}

void		rooms(t_map *map, char *line)
{
	map->started = 2;
	map->rooms_list = join_str(map->rooms_list, line, 0);
	if (line[0] == '#')
		return ;
	validate_room(map, line);
	map->q_rooms++;
}
