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

room_s	*set_room(room_s *room, info_s *info)
{
	room_s **copy;

	info->ants = set_ants(info);
	if (info->exit == -1) {
		info->exit = -1;
		return (NULL);
	}
	print_message(info);
	if (init_room(info) == 84)
		return (NULL);
	if (test_error(info) == 84) {
		info->exit = -1;
		return (NULL);
	}
	copy = make_room(info);
	if (info->exit == -1)
		return (NULL);
	room = link_path(room, copy, info);
	return (room);
}

room_s	**make_room(info_s *info)
{
	room_s **copy = NULL;
	int array = 0;
	int tab = 1;

	while (info->path[tab] != NULL) {
		if (find_arrow(info->path[tab]) == 0
		&& info->path[tab][0] != '#')
			array += 1;
		tab += 1;
	}
	tab = 1;
	copy = malloc(sizeof(room_s) * (array + 2));
	if (copy == NULL) {
		info->exit = -1;
		return (NULL);
	}
	array = 0;
	copy_array_in_make_room(info, tab, array, copy);
	return (copy);
}

int	set_point(info_s *info, char *line)
{
	if (line[0] == '#' && line[1] == '#') {
		if (my_strncmp(line, "##start", 8)) {
			my_putstr(1, line);
			my_putchar('\n');
			if ((info->start = fill_point(info)) == NULL)
				return (84);
		}
		else if (my_strncmp(line, "##end", 6)) {
			my_putstr(1, line);
			my_putchar('\n');
			if ((info->end = fill_point(info)) == NULL)
				return (84);
		}
	}
	return (0);
}

char	*fill_point(info_s *info)
{
	char *line = NULL;
	char *point = NULL;
	int carac = 0;

	line = get_next_line(0);
	if (line == NULL) {
		info->exit = -1;
		return (NULL);
	}
	my_putstr(1, line);
	my_putchar('\n');
	save_path(info, line);
	point = malloc(sizeof(char) * ((my_strlen(take_name(line))) + 1));
	if (point == NULL) {
		info->exit = -1;
		return (NULL);
	}
	end_of_fill_point(line, &carac, point);
	return (point);
}

int	set_ants(info_s *info)
{
	char *line = NULL;

	while (1) {
		line = get_next_line(0);
		if (line == NULL) {
			info->exit = -1;
			return (84);
		}
		if (line[0] != '#') {
			save_path(info, line);
			return (my_getnbr(line));
		}
	}
}
