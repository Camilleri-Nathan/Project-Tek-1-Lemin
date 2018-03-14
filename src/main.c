/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** By Camilleri Nathan
*/

#include "struct.h"
#include "init_lemin.h"
#include <stdlib.h>

int	main()
{
	room_s *room;

	room = NULL;
	set_room(&room, "asset/map007");
	return (0);
}
