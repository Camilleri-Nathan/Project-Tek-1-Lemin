/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** struct.h
*/

typedef struct room_struct {
	char *name;
	int nb_way;
	struct room_struct **next;
} room_s;
