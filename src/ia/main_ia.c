/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** algo ia lemin
*/

#include <stdbool.h>

typedef struct room_struct {
        char *name;
        int nb_way;
        struct room_struct **next;
} room_s;

/************* A METTRE DANS UN INCLUDE ************/
// #define	END_ROOM		-1
// #define	START_ROOM		-2


room_s	*search_end(room_s *rooms)
{
	room_s	*tmp = rooms;

	while (my_strcmp(tmp->name, "end") != 0 &&
		tmp != NULL)
		tmp = tmp->next;
	if (tmp == NULL)
		return (NULL);
	tmp->nb_way = END_ROOM;
	return (tmp);
}

bool	fill_start(room_s *room)
{
	room_s	*tmp = room;

	while (my_strcmp(tmp->name, "start") != 0 &&
	tmp != NULL)
		tmp = tmp->next;
	if (tmp == NULL)
		return (false);
	tmp->nb_way = START_ROOM;
	return (true);
}

bool	check_fill_room(room_s *rooms)
{
	room_s	*tmp = rooms;

	while (tmp != NULL) {
		if (tmp->nb_way == 0)
			return (false)
		tmp = tmp->next;
	}
	return (true);
}

void	fill_one_room(int *count_room, int *count_n, room_s *tmp)
{
	room_s	*save = tmp;

	if (my_strcmp(tmp->next[*count_n]->name, "start") != 0 &&
	    (tmp->next[*count_n]->nb_way == 0 ||
	     tmp->next[*count_n]->nb_way > (*count_room) + 1)) {
		(*count_room)++;
		tmp = tmp->next;
		tmp->nb_way = (*count_room);
		(*count_n) = 0;
	}
	else if (tmp->next[*count_n + 1])
		(*count_n)++;
	else {
		tmp = tmp->prev;
		(*count_room)--;
		(*count_n) = 0;
	}
}

int	fill_all_rooms(room_s *rooms)
{
	room_s	*tmp = search_end(rooms);
	int	count_n = 0;
	int	count_room = 0;

	if (fill_start == false || tmp == NULL)
		return (ERROR);
	while (check_fill_room(rooms) != true) {
		fill_one_room(&count_room, &count_n, tmp);
	}
}
