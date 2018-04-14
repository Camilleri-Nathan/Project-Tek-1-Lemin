/*
** EPITECH PROJECT, 2018
** find_way.c
** File description:
** contain function to find the best way
*/

#include <stdlib.h>
#include "find_lemin.h"
#include "tools_lemin.h"
#include "struct.h"

room_s	*link_path_way_2(path_s *path, info_s *info)
{
	if (path->over[0] != NULL)
		if (my_strncmp(info->start,
			path->over[nb_array(path->over) - 1]->name,
			my_strlen(info->start)))
			info->exit = -1;
	return (0);
}

void 	link_path_way_3(path_s *path, room_s *room)
{
	path->over = add_array(room, path->over);
	if (nb_array(path->prev) == 0) {
		room = path->prev[nb_array(path->prev)];
		path->prev[nb_array(path->prev)] = NULL;
	} else {
		room = path->prev[nb_array(path->prev) - 1];
		path->prev[nb_array(path->prev) - 1] = NULL;
	}
}
