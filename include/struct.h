/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct room_struct {
	char *name;
	int nb_way;
	struct room_struct **next;
} room_s;

typedef struct prev_struct {
	int way;
	room_s *room;
} prev_s;

typedef struct info_struct {
	char **path;
	char *start;
	char *end;
	int ants;
} info_s;

#endif /* STRUCT_H_ */
