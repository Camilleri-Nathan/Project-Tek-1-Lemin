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

int	check_nb_start(info_s *info)
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

int	check_nb_end(info_s *info)
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

int	test_error(info_s *info)
{
	int check_start = 0;
	int check_end = 0;

	check_start = check_nb_start(info);
	check_end = check_nb_end(info);
	if (check_start != 1 || check_end != 1) {
		info->exit = -1;
		return (84);
	}
	return (0);
}
