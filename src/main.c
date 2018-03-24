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
	int ants = 0;
	char *start = NULL;
	char *end = NULL;
	
	room = NULL;
	set_room(&room, &ants, start, end);
	return (0);
}
