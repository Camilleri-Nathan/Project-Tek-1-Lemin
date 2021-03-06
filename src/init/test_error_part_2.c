/*
** EPITECH PROJECT, 2018
** lem in
** File description:
** error map part 2
*/

#include "struct.h"
#include "init_lemin.h"
#include "tools_lemin.h"
#include "get_next_line.h"
#include <stdlib.h>

#include <stdio.h>

static int	check_three_av(char *str)
{
	int index = 0;

	if (str[0] == '#')
		return (1);
	while (str[index] != '\0' && str[index] != ' ')
		index++;
	index++;
	while (str[index] != ' ') {
		if (str[index] < '0' || str[index] > '9')
			return (-1);
		index++;
	}
	index++;
	while (str[index] != '\0' && str[index] != '\n') {
		if (str[index] < '0' || str[index] > '9') {
			return (-1);
		}
		index++;
	}
	return (0);
}

static int	check_space_av(info_s *info, int *index)
{
	int space = 0;

	while (info->path[*index] != NULL &&
	my_strcmp(info->path[*index], "##end")) {
		space = counter_space(info->path[*index]);
		if (space > 2)
			return (84);
		else {
			if (check_three_av(info->path[*index]) == -1)
				return (84);
		}
		space = 0;
		*index += 1;
	}
	(*index)++;
	return (0);
}

static int	check_space_and_hyphen(char *path, int *nbr_tunnel,
				int space, int *hyphen)
{
	if (space == 1 || space > 2)
		return (-1);
	else if (space == 0 && (*hyphen = counter_hyphen(path)) != -1) {
		if (*hyphen != 1)
			return (-1);
		(*nbr_tunnel)++;
	}
	return (0);
}

static int	check_space_end_av(info_s *info, int *index)
{
	int nbr_tunnel = 0;
	int hyphen = 0;
	int space = 0;

	while (info->path[*index] != NULL) {
		space = counter_space(info->path[*index]);
		if (space != -1) {
			if (check_space_and_hyphen(info->path[*index],
			&nbr_tunnel, space, &hyphen) == -1)
				return (-1);
		}
		else if (check_three_av(info->path[*index]) == -1)
			return (-1);
		(*index)++;
	}
	return (nbr_tunnel);
}

int	check_nb_av_and_type(info_s *info)
{
	int index = 0;
	int check_space = 0;
	int check_space_end = 0;

	while (info->path[index] != NULL &&
	my_strcmp(info->path[index], "##start"))
		index++;
	index++;
	check_space = check_space_av(info, &index);
	if (check_space == 84)
		return (84);
	check_space_end = check_space_end_av(info, &index);
	if (check_space_end <= 0)
		return (84);
	return (0);
}
