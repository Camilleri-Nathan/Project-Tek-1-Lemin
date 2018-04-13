/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** part 2
*/

#include "struct.h"
#include "init_lemin.h"
#include "get_next_line.h"
#include "tools_lemin.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	copy_array_in_make_room(info_s *info, int tab,
				int array, room_s **copy)
{
	while (info->path[tab] != NULL) {
		if (find_arrow(info->path[tab]) == 0
		&& info->path[tab][0] != '#') {
			copy[array] = add_room(info->path[tab]);
			array += 1;
		}
		tab += 1;
	}
	copy[array] = NULL;
}

void	end_of_fill_point(char *line, int *carac, char *point)
{
	while (line[*carac] != ' ' && line[*carac] != '\0') {
		point[*carac] = line[*carac];
		*carac += 1;
	}
	point[*carac] = '\0';
}
