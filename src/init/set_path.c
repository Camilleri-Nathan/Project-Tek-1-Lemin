/*
** EPITECH PROJECT, 2018
** set_path.c
** File description:
** function to set all path with room
*/

#include "struct.h"
#include "init_lemin.h"
#include "tools_lemin.h"
#include <stdlib.h>
#include <stdio.h>

room_s	*link_path(room_s *room, room_s **copy, info_s *info)
{
	room = copy[0];
	link_room(info, room, copy);
	if (test_link_first(info)) {
		info->exit = -1;
		return (room);
	}
	set_path(room, copy, info);
	return (room);
}

void	link_room(info_s *info, room_s *room, room_s **copy)
{
	int array = 0;
	int tab = 0;

	while (info->path[array]) {
		while (copy[tab] != NULL) {
			if (find_arrow(info->path[array]) == 0)
				break;
			add_link(take_first(info->path[array]),
			take_second(info->path[array]), room, copy[tab]);
			add_link(take_second(info->path[array]),
			take_first(info->path[array]), room, copy[tab]);
			tab += 1;
		}
		tab = 0;
		array += 1;
	}
}

void	add_link(char *first, char *second, room_s *room, room_s *copy)
{
	if (my_strncmp(first, room->name, my_strlen(room->name + 1))) {
		if (my_strncmp(second, copy->name,
			my_strlen(room->name + 1)))
			make_path(room, copy);
	}
}

room_s	*add_room(char *line)
{
	room_s *buff;
	char *name = take_name(line);

	buff = malloc(sizeof(room_s));
	buff->name = name;
	buff->nb_way = 0;
	buff->next = malloc(sizeof(room_s *) * 2);
	buff->next[0] = NULL;
	return (buff);
}

void	make_path(room_s *room, room_s *save)
{
	room_s **copy;
	int array = 0;

	copy = malloc(sizeof(room_s *) * (room->nb_way + 1));
	while (room->next[array] != NULL) {
		copy[array] = room->next[array];
		array += 1;
	}
	copy[array] = NULL;
	array = 0;
	room->next = malloc(sizeof(room_s *) * (room->nb_way + 2));
	while (copy[array] != NULL) {
		room->next[array] = copy[array];
		array += 1;
	}
	room->next[array] = save;
	room->next[array + 1] = NULL;
	room->nb_way += 1;
}
