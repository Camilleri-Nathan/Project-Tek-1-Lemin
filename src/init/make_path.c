/*
** EPITECH PROJECT, 2018
** make_path.c
** File description:
** contain function to set all path
*/

#include "struct.h"
#include "init_lemin.h"
#include "tools_lemin.h"
#include <stdlib.h>
#include <stdio.h>

void	set_path(room_s *room, room_s **copy, info_s *info)
{
	room_s *prev = NULL;
	int way = 0;

	prev = room;
	while (1) {
		room = prev;
		if (room->next[way] == NULL)
			break;
		room = room->next[way];
		way += 1;
		link_room(info, room, copy);
		room = room->next[way];
		set_path(room, copy, info);
	}
}

void	save_path(info_s *info, char *line)
{
	int array = 0;
	int carac = 0;

	info->path = realloc_path(info->path, &array);
	info->path[array] = malloc(sizeof(char) * (my_strlen(line) + 1));
	while (line[carac] != '\0') {
		info->path[array][carac] = line[carac];
		carac += 1;
	}
	info->path[array][carac] = '\0';
	info->path[array + 1] = NULL;
}

char	**realloc_path(char **path, int *array)
{
	char **copy = make_copy(path);
	int tab = 0;
	int carac = 0;
	
	while (path[*array] != NULL) {
		*array += 1;
	}
	path = malloc(sizeof(char *) * (*array + 2));
	while (tab != *array) {
		path[tab] = malloc(sizeof(char) * (my_strlen(copy[tab]) + 1));
		while (copy[tab][carac] != '\0') {
			path[tab][carac] = copy[tab][carac];
			carac += 1;
		}
		path[tab][carac] = '\0';
		carac = 0;
		tab += 1;
	}
	free(copy);
	return (path);
}

char	**make_copy(char **path)
{
	char **copy = NULL;
	int array = 0;
	int carac = 0;

	while (path[array] != NULL)
		array += 1;
	copy = malloc(sizeof(char *) * (array + 1));
	array = 0;
	while (path[array] != NULL) {
		copy[array] = malloc(sizeof(char) *
			(my_strlen(path[array]) + 1));
		while (path[array][carac] != '\0') {
	        	copy[array][carac] = path[array][carac];
			carac += 1;
		}
		copy[array][carac] = '\0';
		carac = 0;
		array += 1;
	}
	copy[array] = NULL;
	return (copy);
}
