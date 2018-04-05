/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** find lemin
*/

#ifndef	FIND_LEMIN_H_
#define	FIND_LEMIN_H_

#include "struct.h"

// ___ find_way.c ___

path_s	find_way(room_s *room, info_s *info);
room_s	*link_path_way(path_s *path, room_s *room, info_s *info);
room_s	**add_array(room_s *room, room_s **array);
int	test_over(room_s *room, room_s **prev, room_s **over, int array);
int	nb_array(room_s **array);

#endif		/* FIND_LEMIN_H_ */
