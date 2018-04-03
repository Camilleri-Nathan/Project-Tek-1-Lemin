/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** By Camilleri Nathan
*/

#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "init_lemin.h"
#include "tools_lemin.h"
#include "find_lemin.h"

int	main(void)
{
	room_s *room;
	info_s info;

	room = NULL;
	info.exit = 0;
	info.path = malloc(sizeof(char *) * 2);
	info.path[0] = NULL;
	room = set_room(room, &info);
	if (info.exit == -1)
		return (84);
	my_putstr(1, "#moves\n");
	find_way(room, &info);
	return (0);
}
