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

static void	delete_ant(ant_s **all_ant)
{
	ant_s	*tmp = *all_ant;
	ant_s	*tmp2 = NULL;

	if (tmp != NULL && tmp->next == NULL) {
		free(tmp);
		tmp = NULL;
	} else {
		tmp2 = tmp->next;
		free(tmp);
		*all_ant = tmp2;
	}
}

void	check_end(ant_s **all_ant, path_s path)
{
	if ((*all_ant) != NULL && path.prev[(*all_ant)->nbr_room] == NULL)
		delete_ant(all_ant);
}
