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

path_s	find_way(room_s *room, info_s *info)
{
	path_s path;

	path.prev = malloc(sizeof(room_s *) * 2);
	path.over = malloc(sizeof(room_s *) * 2);
	path.over[0] = NULL;
	path.prev[0] = NULL;
	path.array = 0;
	while (1) {
		room = link_path_way(&path, room, info);
		if (info->exit == -1)
			return (path);
		if (my_strncmp(info->end, room->name, my_strlen(info->end)))
			break;
		path.array = 0;
	}
	return (path);
}

room_s	*link_path_way(path_s *path, room_s *room, info_s *info)
{
	while (1) {
		if (room->next[path->array] != NULL
		&& test_over(room, path->prev, path->over, path->array) == 0) {
			path->prev = add_array(room, path->prev);
			room = room->next[path->array];
			break;
		}
		else if (room->next[path->array] == NULL) {
			path->over = add_array(room, path->over);
			room = path->prev[nb_array(path->prev) - 1];
			path->prev[nb_array(path->prev) - 1] = NULL;
			break;
		}
		path->array += 1;
	}
	link_path_way_2(path, info);
	return (room);
}

int	nb_array(room_s **array)
{
	int tab = 0;

	while (array[tab] != NULL)
		tab += 1;
	return (tab);
}

room_s	**add_array(room_s *room, room_s **array)
{
	room_s **copy;
	int tab = 0;

	copy = malloc(sizeof(room_s *) * (nb_array(array) + 2));
	while (array[tab] != NULL) {
		copy[tab] = array[tab];
		tab += 1;
	}
	copy[tab] = NULL;
	array = malloc(sizeof(room_s *) * (tab + 2));
	tab = 0;
	while (copy[tab] != NULL) {
		array[tab] = copy[tab];
		tab += 1;
	}
	array[tab] = room;
	array[tab + 1] = NULL;
	return (array);
}

int	test_over(room_s *room, room_s **prev, room_s **over, int array)
{
	room_s *copy = room;
	int tab = 0;

	copy = copy->next[array];
	while (prev[tab] != NULL) {
		if (my_strncmp(prev[tab]->name, copy->name,
			my_strlen(copy->name)))
			return (1);
		tab += 1;
	}
	tab = 0;
	while (over[tab] != NULL) {
		if (my_strncmp(over[tab]->name,
			copy->name, my_strlen(copy->name)))
			return (1);
		tab += 1;
	}
	return (0);
}
