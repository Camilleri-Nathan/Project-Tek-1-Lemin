/*
** EPITECH PROJECT, 2018
** find_way.c
** File description:
** contain function to find the best way
*/

#include <stdlib.h>
#include "find_lemin.h"
#include "tools_lemin.h"
#include "struct.h"

void	find_way(room_s *room, info_s *info)
{
	room_s **prev;
	room_s **over;
	int array = 0;

	prev = malloc(sizeof(room_s *) * 2);
	over = malloc(sizeof(room_s *) * 2);
	over[0] = NULL;
	prev[0] = NULL;
	while (1) {
		while (1) {
			if (room->next[array] != NULL
			    && test_over(room, prev, over, array) == 0) {
				prev = add_array(room, prev);
				room = room->next[array];
				break;
			}
			else if (room->next[array] == NULL) {
				over = add_array(room, over);
				room = prev[nb_array(prev) - 1];
				prev[nb_array(prev) - 1] = NULL;
				break;
			}
			array += 1;
		}
		if (my_strncmp(info->end, room->name, my_strlen(info->end)))
			break;
		array = 0;
	}
}

int	nb_array(room_s **array)
{
	int tab = 0;

	while (array[tab] != NULL)
		tab += 1;
	return (tab);
}

room_s	**add_array(room_s *room, room_s **array)
{
	room_s **copy;
	int tab = 0;

	copy = malloc(sizeof(room_s *) * (nb_array(array) + 2));
	while (array[tab] != NULL) {
		copy[tab] = array[tab];
		tab += 1;
	}
	copy[tab] = NULL;
	array = malloc(sizeof(room_s *) * (tab + 2));
	tab = 0;
	while (copy[tab] != NULL) {
		array[tab] = copy[tab];
		tab += 1;
	}
	array[tab] = room;
	array[tab + 1] = NULL;
	return (array);
}

int	test_over(room_s *room, room_s **prev, room_s **over, int array)
{
	room_s *copy = room;
	int tab = 0;

	copy = copy->next[array];
	while (prev[tab] != NULL) {
		if (my_strncmp(prev[tab]->name,
		copy->name, my_strlen(copy->name)))
			return (1);
		tab += 1;
	}
	tab = 0;
	while (over[tab] != NULL) {
		if (my_strncmp(over[tab]->name,
		copy->name, my_strlen(copy->name)))
			return (1);
		tab += 1;
	}
	return (0);
}
