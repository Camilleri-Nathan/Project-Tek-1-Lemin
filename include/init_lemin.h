/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** init lemin
*/

#ifndef	INIT_LEMIN_H_
#define	INIT_LEMIN_H_

// ___ init_room.c ___

int	set_room(room_s **room, info_s *info);
int	add_room(room_s **room, char *line);
int	set_ants(void);
void	set_point(room_s **room, char **start, char **end, char *line);
char	*fill_point(room_s **room);

// ___ take_value.c ___

char	*take_name(char *line);

// ___ make_path.c ___

void	save_path(info_s *info, char *line);
char	**realloc_path(char **path, int *array);
char	**make_copy(char **path);

// ___ set_path.c ___

void	link_path(room_s **room, room_s **copy, info_s *info);

#endif		/* TOOLS_LEMIN_H_ */
