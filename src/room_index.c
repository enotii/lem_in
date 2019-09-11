/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:46:29 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/11 15:03:43 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	room_index(t_map *map, char *room_name, int start)
{
	int index;

	index = (start) ? -1 : 0;
	while (map->rooms[++index] && index < map->q_rooms)
	{
		if (ft_strcmp(map->rooms[index], room_name) == 0)
			return (index);
	}
	return (index);
}
