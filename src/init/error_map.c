/*
** EPITECH PROJECT, 2018
** lem in
** File description:
** manage the error
*/

#include "struct.h"
#include "init_lemin.h"
#include "tools_lemin.h"
#include "get_next_line.h"
#include <stdlib.h>

static int	check_nb_start(info_s *info)
{
	int index = 0;
	int check_start = 0;

	while (info->path[index] != NULL) {
		if (!my_strcmp(info->path[index], "##start")) {
			check_start++;
		}
		index++;
	}
	return (check_start);
}

static int	check_nb_end(info_s *info)
{
	int index = 0;
	int check_end = 0;

	while (info->path[index] != NULL) {
		if (!my_strcmp(info->path[index], "##end")) {
			check_end++;
		}
		index++;
	}
	return (check_end);
}

static int	check_nb_ants(info_s *info)
{
	int index = 0;
	int space = 0;

	while (my_strcmp(info->path[index], "##start")) {
		while (info->path[index][0] == '#')
			index++;
		if (my_str_isnum(info->path[index]) == 84)
			return (84);
		index++;
		if (info->path[index][0] == '#' && info->path[index][1] == '#')
			return (0);
		if ((my_strcmp(info->path[index], "##start") == 0) ||
		(space = counter_space(info->path[index])) != 2)
			return (84);
		index++;
	}
	if (index == 0)
		return (84);
	return (0);
}

static int	test_error_suit(info_s *info, int *check_after, int *check_type)
{
	*check_after = check_after_start_and_end(info);
	if (*check_after == 84) {
		info->exit = -1;
		return (84);
	}
	*check_type = check_nb_av_and_type(info);
	if (*check_type == 84) {
		info->exit = -1;
		return (84);
	}
	return (0);
}

int	test_error(info_s *info)
{
	int check_start = 0;
	int check_end = 0;
	int check_ants = 0;
	int check_after = 0;
	int check_type = 0;

	check_start = check_nb_start(info);
	check_end = check_nb_end(info);
	if (check_start != 1 || check_end != 1) {
		info->exit = -1;
		return (84);
	}
	check_ants = check_nb_ants(info);
	if (check_ants == 84) {
		info->exit = -1;
		return (84);
	}
	if (test_error_suit(info, &check_after, &check_type) == 84)
		return (84);
	return (0);
}
