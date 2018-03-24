/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** init_room.c
*/

#include "struct.h"
#include "init_lemin.h"
#include "get_next_line.h"
#include "tools_lemin.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	set_room(room_s **room, int *ants, char *start, char *end)
{
	int ants;
	char *line = NULL;

	*ants = set_ants();
	line = get_next_line(0);
	while (line != NULL) {
		if (line[0] == '#')
			set_point(room, start, end);
		else if (find_arrow(line))
			*ants = *ants; // make path
		else if (line[0] != '#')
			add_room(room, line);
		line = get_next_line(0);
	}
	return (0);
}

void	set_point(room_s **room, char *start, char *end)
{
	
}

int	add_room(room_s **room, char *line)
{
	room_s *buff;
	char *name = take_name(line);

	buff = malloc(sizeof(room_s));
	buff->name = name;
	buff->nb_way = 0;
	buff->next = malloc(sizeof(room_s) * 2);
	buff->next[0] = *room;
	*room = buff;
	return (0);
}

int	set_ants(void)
{
	char *line = NULL;

	while (1) {
		line = get_next_line(0);
		if (line[0] != '#')
			return (my_getnbr(line));
	}
}
