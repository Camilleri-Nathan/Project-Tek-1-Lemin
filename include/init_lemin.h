/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** init lemin
*/

#ifndef	INIT_LEMIN_H_
#define	INIT_LEMIN_H_

// ___ init_room.c ___

int	set_room(room_s **room, char *file_name);
int	add_room(room_s **room, char *line);

// ___ take_value.c ___

char	*take_name(char *line);

#endif		/* TOOLS_LEMIN_H_ */
