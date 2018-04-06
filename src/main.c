/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** By Camilleri Nathan
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "struct.h"
#include "init_lemin.h"
#include "tools_lemin.h"
#include "find_lemin.h"

bool	init_info(info_s *info)
{
	info->exit = 0;
	info->path = malloc(sizeof(char *) * 2);
	if (info->path == NULL)
		return (false);
	info->path[0] = NULL;
	return (true);
}

void	init_enter_of_room(room_s **room)
{
	int	count = 0;
	room_s	**tmp = room;

	while (tmp[count] != NULL) {
		tmp[count]->enter_in_room = false;
		count++;
	}
}

int	main(void)
{
	room_s *room = NULL;
	info_s info;
	path_s path;

	if (init_info(&info) == false)
		return (84);
	room = set_room(room, &info);
	if (info.ants < 1 || info.exit == -1 || room == NULL)
		return (84);
	my_putstr(1, "#moves\n");
	path = find_way(room, &info);
	if (info.exit == -1)
		return (84);
	init_enter_of_room(path.prev);
	if (send_and_display_ant(info, path) == 84)
		return (84);
	return (0);
}
