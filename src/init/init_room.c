/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** init_room.c
*/

#include "struct.h"
#include "init_lemin.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	set_room(room_s **room, char *file_name)
{
	int file;
	int ants;
	char *line = NULL;

	file = open(file_name, O_RDONLY);
	line = get_next_line(file);
	if (line[0] == '#')
		(void)ants;
	add_room(room, line);
	close(file);
	return (0);
}

int	add_room(room_s **room, char *line)
{
	room_s *buff;
	char *name = take_name(line);

	buff = malloc(sizeof(room_s));
	*buff->name = *name;
	buff->nb_way = 0;
	buff->way = NULL;
	buff->next = *room;
	*room = buff;
	return (0);
}
