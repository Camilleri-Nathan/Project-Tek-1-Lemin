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
	my_putstr(1, "#number_of_ants\n");
	my_put_nbr(info->ants);
	my_putchar('\n');
	my_putstr(1, "#rooms\n");
	if (init_room(info) == 84)
		return (NULL);
	if (test_error(info) == 84)
		return (NULL);
	copy = make_room(info);
	room = link_path(room, copy, info);
	return (room);
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
			my_putstr(1, line);
			my_putchar('\n');
			info->start = fill_point(info);
		}
		else if (my_strncmp(line, "##end", 6)) {
			my_putstr(1, line);
			my_putchar('\n');
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
	if (line == NULL) {
		info->exit = -1;
		return (NULL);
	}
	my_putstr(1, line);
	my_putchar('\n');
	save_path(info, line);
	point = malloc(sizeof(char) * ((my_strlen(take_name(line))) + 1));
	while (line[carac] != ' ' && line[carac] != '\0') {
		point[carac] = line[carac];
		carac += 1;
	}
	point[carac] = '\0';
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
		if (line[0] != '#')
			return (my_getnbr(line));
	}
}
