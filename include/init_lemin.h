/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** init lemin
*/

#ifndef	INIT_LEMIN_H_
#define	INIT_LEMIN_H_

// ___ init_room.c ___

int	set_room(room_s **room);
int	add_room(room_s **room, char *line);
int	set_ants(void);

// ___ take_value.c ___

char	*take_name(char *line);

#endif		/* TOOLS_LEMIN_H_ */
