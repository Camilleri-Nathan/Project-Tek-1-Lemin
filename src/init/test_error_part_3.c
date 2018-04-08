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

int	check_after_start_and_end(info_s *info)
{
	int index = 0;

	while (info->path[index] != NULL &&
	my_strcmp(info->path[index], "##start"))
		index++;
	index++;
	if (info->path[index][0] == '#') {
		return (84);
	}
	while (info->path[index] != NULL &&
	my_strcmp(info->path[index], "##end")){
		index++;
	}
	index++;
	if (info->path[index] == NULL || info->path[index][0] == '#' ||
	info->path[index][0] == '\0')
		return (84);
	return (0);
}
