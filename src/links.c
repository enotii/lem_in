/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 13:24:40 by ashulha           #+#    #+#             */
/*   Updated: 2019/09/10 19:51:24 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	links(t_map *m, char *line)
{
	if (m->started == 2)
		m->started = 3;
	if (m->started != 3)
		exit_func(m, 1);
	m->links = join_str(m->links, line, 0);
}
