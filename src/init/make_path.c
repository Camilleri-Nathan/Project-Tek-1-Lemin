/*
** EPITECH PROJECT, 2018
** make_path.c
** File description:
** contain function to set all path
*/

#include "struct.h"
#include "init_lemin.h"
#include "tools_lemin.h"
#include "find_lemin.h"
#include <stdlib.h>
#include <stdio.h>

void	set_path(room_s *room, room_s **copy, info_s *info)
{
	path_s path;

	path.prev = malloc(sizeof(room_s *) * 2);
	if (path.prev == NULL) {
		info->exit = -1;
		return;
	}
	if ((path.over = malloc(sizeof(room_s *) * 2)) == NULL) {
		info->exit = -1;
		return;
	}
	path.over[0] = NULL;
	path.prev[0] = NULL;
	path.array = 0;
	while (1) {
		room = link_path_create(&path, room, copy, info);
		if (nb_array(path.over) == nb_array(copy))
			break;
		path.array = 0;
	}
}

room_s	*link_path_create(path_s *path, room_s *room, room_s **copy,
			info_s *info)
{
	while (1) {
		if (room->next[path->array] != NULL
		&& test_over(room, path->prev, path->over, path->array) == 0) {
			path->prev = add_array(room, path->prev);
			room = room->next[path->array];
			link_room(info, room, copy);
			break;
		}
		else if (room->next[path->array] == NULL) {
			path->over = add_array(room, path->over);
			room = path->prev[nb_array(path->prev) - 1];
			break;
		}
		path->array += 1;
	}
	return (room);
}

void	save_path(info_s *info, char *line)
{
	int array = 0;
	int carac = 0;

	info->path = realloc_path(info->path, &array, info);
	info->path[array] = malloc(sizeof(char) * (my_strlen(line) + 1));
	if (info->path[array] == NULL) {
		info->exit = -1;
		return;
	}
	while (line[carac] != '\0') {
		info->path[array][carac] = line[carac];
		carac += 1;
	}
	info->path[array][carac] = '\0';
	info->path[array + 1] = NULL;
}

char	**realloc_path(char **path, int *array, info_s *info)
{
	char **copy = make_copy(path, info);
	int tab = 0;

	if (info->exit == -1)
		return (NULL);
	while (path[*array] != NULL)
		*array += 1;
	path = malloc(sizeof(char *) * (*array + 2));
	if (path == NULL)
		return (info->exit = -1, NULL);
	while (tab != *array) {
		path[tab] = my_strdup(copy[tab]);
		if (path[tab] == NULL)
			return (info->exit = -1, NULL);
		tab += 1;
	}
	free(copy);
	return (path);
}

char	**make_copy(char **path, info_s *info)
{
	char **copy = NULL;
	int array = 0;

	while (path[array++] != NULL);
	copy = malloc(sizeof(char*) * (array + 1));
	if (copy == NULL)
		return (info->exit = -1, NULL);
	array = 0;
	while (path[array] != NULL) {
		copy[array] = my_strdup(path[array]);
		if (copy[array] == NULL)
			return (info->exit = -1, NULL);
		array += 1;
	}
	copy[array] = NULL;
	return (copy);
}
