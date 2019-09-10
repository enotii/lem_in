/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 21:19:39 by ashulha           #+#    #+#             */
/*   Updated: 2019/09/10 19:51:27 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	room_index(t_map *m, char *room_name, int start)
{
	int index;

	index = (start) ? -1 : 0;
	while (m->rooms[++index] && index < m->q_rooms)
	{
		if (ft_strcmp(m->rooms[index], room_name) == 0)
			return (index);
	}
	return (index);
}
