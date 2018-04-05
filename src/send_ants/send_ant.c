/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** send ant
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "find_lemin.h"
#include "tools_lemin.h"
#include "struct.h"

bool	init_new_ant(ant_s **all_ant, int ant_name)
{
	ant_s	*new_ant = malloc(sizeof(ant_s));
	ant_s	*tmp = *all_ant;

	if (new_ant == NULL)
		return (false);
	new_ant->nbr_ant = ant_name;
	new_ant->nbr_room = 0;
	new_ant->next = NULL;
	if (*all_ant == NULL)
		*all_ant = new_ant;
	else {
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_ant;
	}
	return (true);
}

bool	init_ant(info_s info, ant_s **all_ant)
{
	int	nbr_ant = 1;

	while (nbr_ant <= info.ants) {
		if (init_new_ant(all_ant, nbr_ant) == false)
			return (false);
		nbr_ant++;
	}
	return (true);
}


void	delete_ant(ant_s **all_ant)
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

int	send_and_display_ant(info_s info, path_s path)
{
	ant_s		*all_ant = NULL;

	if (init_ant(info, &all_ant) == false)
		return (84);
	while (all_ant->next != NULL) {
		check_end(&all_ant, path);
		nominate_room(all_ant, path);
		display_ant_in_room(all_ant, path, info);
		my_putstr(1, "\n");
	}
	return (0);
}
