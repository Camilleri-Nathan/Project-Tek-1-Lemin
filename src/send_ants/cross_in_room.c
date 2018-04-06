/*
** EPITECH PROJECT, 2017
** cross_in_room.c
** File description:
** By Camilleri Nathan
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "find_lemin.h"
#include "tools_lemin.h"
#include "struct.h"

static int	counter_room(path_s path)
{
	static unsigned int	save = 0;
	unsigned int		room = 0;

	while (path.prev[room + 1] != NULL &&
	path.prev[room + 1]->enter_in_room == true) {
		room++;
	}
	room++;
	if (save < room)
		save = room;
	return (save);
}

void	nominate_room(ant_s *all_ant, path_s path)
{
	ant_s	*tmp = all_ant;
	unsigned int	room = 0;

	room = counter_room(path);
	while (tmp != NULL && room != 0) {
		tmp->nbr_room = room;
		if (path.prev[tmp->nbr_room] != NULL)
		path.prev[tmp->nbr_room]->enter_in_room = true;
		room--;
		tmp = tmp->next;
	}
}

void	display_ant_in_room(ant_s *all_ant, path_s path, info_s info)
{
	char	*name_room = NULL;
	ant_s	*tmp = all_ant;

	while (tmp != NULL && tmp->nbr_room > 0) {
		if (path.prev[tmp->nbr_room] == NULL)
			name_room = info.end;
		else {
			name_room = path.prev[tmp->nbr_room]->name;
		}
		my_putstr(1, "P");
		my_put_nbr(tmp->nbr_ant);
		my_putstr(1, "-");
		my_putstr(1, name_room);
		if (tmp != NULL && tmp->next != NULL &&
			tmp->next->nbr_room != 0)
			my_putstr(1, " ");
		tmp = tmp->next;
	}
}
