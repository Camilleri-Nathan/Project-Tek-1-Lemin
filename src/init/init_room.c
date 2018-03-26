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

int	set_room(room_s **room, info_s *info)
{
	room_s *copy;
	char *line = NULL;

	copy = NULL;
	info->ants = set_ants();
	line = get_next_line(0);
	if (line == NULL)
		return (84);
	while (line != NULL) {
		if (line[0] == '#')
			set_point(&copy, &info->start, &info->end, line);
		else if (find_arrow(line))
			save_path(info, line);
		else if (line[0] != '#')
			add_room(&copy, line);
		line = get_next_line(0);
	}
	link_path(room, &copy, info);
	return (0);
}

void	set_point(room_s **room, char **start, char **end, char *line)
{
	if (line[0] == '#' && line[1] == '#') {
		if (my_strncmp(line, "##start", 8)) {
			*start = fill_point(room);
		}
		else if (my_strncmp(line, "##end", 6)) {
			*end = fill_point(room);
		}
	}
}

char	*fill_point(room_s **room)
{
	char *line = NULL;
	char *point = NULL;
	int carac = 0;

	line = get_next_line(0);
	add_room(room, line);
	point = malloc(sizeof(char) * ((my_strlen(take_name(line))) + 1));
	while (line[carac] != ' ' && line[carac] != '\0') {
		point[carac] = line[carac];
		carac += 1;
	}
	point[carac] = '\0';
	return (point);
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
