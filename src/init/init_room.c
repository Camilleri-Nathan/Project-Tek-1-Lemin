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

int	set_room(room_s *room, info_s *info)
{
	room_s **copy;
	char *line = NULL;

	info->ants = set_ants();
	line = get_next_line(0);
	if (line == NULL)
		return (84);
	while (line != NULL) {
		if (line[0] == '#')
			set_point(info, line);
		else
			save_path(info, line);
		line = get_next_line(0);
	}
	copy = make_room(info);
	link_path(room, copy, info);
	return (0);
}

room_s	**make_room(info_s *info)
{
	room_s **copy;
	int array = 0;
	int tab = 0;

	while (info->path[tab] != NULL) {
		if (find_arrow(info->path[tab]) == 0)
			array += 1;
		tab += 1;
	}
	tab = 0;
	array = 0;
	copy = malloc(sizeof(room_s) * (array + 2));
	while (info->path[tab] != NULL) {
		if (find_arrow(info->path[tab]) == 0) {
			copy[array] = add_room(info->path[tab]);
			array += 1;
		}
		tab += 1;
	}
	copy[array] = NULL;
	return (copy);
}

void	set_point(info_s *info, char *line)
{
	if (line[0] == '#' && line[1] == '#') {
		if (my_strncmp(line, "##start", 8)) {
			info->start = fill_point(info);
		}
		else if (my_strncmp(line, "##end", 6)) {
			info->end = fill_point(info);
		}
	}
}

char	*fill_point(info_s *info)
{
	char *line = NULL;
	char *point = NULL;
	int carac = 0;

	line = get_next_line(0);
	save_path(info, line);
	point = malloc(sizeof(char) * ((my_strlen(take_name(line))) + 1));
	while (line[carac] != ' ' && line[carac] != '\0') {
		point[carac] = line[carac];
		carac += 1;
	}
	point[carac] = '\0';
	return (point);
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
