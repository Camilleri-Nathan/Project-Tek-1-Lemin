/*
** EPITECH PROJECT, 2017
** check_end.c
** File description:
** By Camilleri Nathan
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "find_lemin.h"
#include "struct.h"

void	check_end(ant_s **all_ant, path_s path)
{
	if ((*all_ant) != NULL && path.prev[(*all_ant)->nbr_room] == NULL)
		delete_ant(all_ant);
}
