/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:46:39 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/11 15:19:07 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	links(t_map *map, char *line)
{
	if (map->started == 2)
		map->started = 3;
	if (map->started != 3)
		exit_func(map, 1);
	map->links = join_str(map->links, line, 0);
}
