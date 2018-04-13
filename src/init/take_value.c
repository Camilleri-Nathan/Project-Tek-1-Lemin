/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** take_value.c
*/

#include "struct.h"
#include "init_lemin.h"
#include "tools_lemin.h"
#include "get_next_line.h"
#include <stdlib.h>

static int	suit_of_init_room(char *line, int *put, info_s *info)
{
	while (line != NULL) {
		if (*put == 0 && find_arrow(line)) {
			my_putstr(1, "#tunnels\n");
			*put = 1;
		}
		if (line[0] == '#') {
			save_path(info, line);
			if (set_point(info, line) == 84)
				return (84);
		}
		else {
			save_path(info, line);
			my_putstr(1, line);
			my_putchar('\n');
		}
		line = get_next_line(0);
	}
	return (0);
}

int	init_room(info_s *info)
{
	char *line = NULL;
	int put = 0;

	line = get_next_line(0);
	if (line == NULL) {
		info->exit = -1;
		return (84);
	}
	if (suit_of_init_room(line, &put, info) == 84)
		return (84);
	return (0);
}

char	*take_name(char *line)
{
	int carac = 0;
	char *name = NULL;

	while (line[carac] != ' ' && line[carac] != '\0') {
		carac += 1;
	}
	name = malloc(sizeof(char) * (carac + 1));
	carac = 0;
	while (line[carac] != ' ' && line[carac] != '\0') {
		name[carac] = line[carac];
		carac += 1;
	}
	name[carac] = '\0';
	return (name);
}

char	*take_first(char *str)
{
	char *string = NULL;
	int carac = 0;

	while (str[carac] != '-' && str[carac] != '\0') {
		carac += 1;
	}
	string = malloc(sizeof(char) * (carac + 1));
	carac = 0;
	while (str[carac] != '-' && str[carac] != '\0') {
		string[carac] = str[carac];
		carac += 1;
	}
	string[carac] = '\0';
	return (string);
}

char	*take_second(char *str)
{
	char *string = NULL;
	int carac = 0;
	int index = 0;

	while (str[carac] != '-' && str[carac] != '\0') {
		carac += 1;
	}
	string = malloc(sizeof(char) * ((my_strlen(str) - carac) + 1));
	carac += 1;
	while (str[carac] != '\0') {
		string[index] = str[carac];
		carac += 1;
		index += 1;
	}
	string[index] = '\0';
	return (string);
}
