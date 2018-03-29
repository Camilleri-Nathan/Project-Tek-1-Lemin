/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** By Camilleri Nathan
*/

#include "struct.h"
#include "init_lemin.h"
#include "tools_lemin.h"
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	room_s *room;
	info_s info;

	room = NULL;
	info.path = malloc(sizeof(char *) * 2);
	info.path[0] = NULL;
	if (set_room(room, &info) == 84)
		return (84);
	my_putstr(1, "#moves\n");
	return (0);
}
