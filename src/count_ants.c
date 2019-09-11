/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:47:05 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/11 15:20:11 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	count_ants(t_map *map, char *line)
{
	int		i;
	char	*s;

	i = 0;
	map->started = 1;
	map->ants_str = join_str(map->ants_str, line, 0);
	if (line[0] == '#')
		return ;
	s = ft_strtrim(line);
	if ((map->ants = ft_atoi(s)) <= 0)
		exit_func(map, 1);
	while (s[i] != '\n' && s[i] != 0)
	{
		if (!ft_isdigit(s[i++]))
			exit_func(map, 1);
	}
}
