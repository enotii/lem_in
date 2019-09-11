/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 19:33:11 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/11 15:14:57 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <limits.h>
# include <stdio.h>

typedef struct	s_map
{
	char		**rooms;
	char		*rooms_list;
	char		*ants_str;
	char		*links;
	int			*path;
	int			**tab;
	int			good[2];
	int			new_line;
	int			init_2;
	int			q_rooms;
	int			ants;
	int			started;
	int			curr_room;
	int			p_ind;
}				t_map;

int				room_index(t_map *map, char *room_name, int start);
int				ft_isspace(char c);
void			result(t_map *map);
void			print_matrix(t_map *map);
void			exit_func(t_map *map, int error);
void			count_ants(t_map *map, char *line);
void			rooms(t_map *map, char *line);
void			links(t_map *map, char *line);
void			add_rooms(t_map *map);
void			create_tab(t_map *map);
int				solution(t_map *map, int i);
char			*join_str(char *s1, char *s2, int clean);
void			free_array(char **array, t_map *map, int error);

#endif
