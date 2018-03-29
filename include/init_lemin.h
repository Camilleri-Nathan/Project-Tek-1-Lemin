/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** init lemin
*/

#ifndef	INIT_LEMIN_H_
#define	INIT_LEMIN_H_

// ___ init_room.c ___

int	set_room(room_s *room, info_s *info);
int	set_ants(void);
void	set_point(info_s *info, char *line);
char	*fill_point(info_s *info);
room_s	**make_room(info_s *info);

// ___ take_value.c ___

int	init_room(info_s *info);
char	*take_name(char *line);
char	*take_first(char *str);
char	*take_second(char *str);

// ___ make_path.c ___

void	set_path(room_s *room, room_s **copy, info_s *info);
void	save_path(info_s *info, char *line);
char	**realloc_path(char **path, int *array);
char	**make_copy(char **path);

// ___ set_path.c ___

void	link_path(room_s *room, room_s **copy, info_s *info);
room_s	*add_room(char *line);
void	make_path(room_s *room, room_s *save);
void	link_room(info_s *info, room_s *room, room_s **copy);
void	add_link(char *first, char *second, room_s *room, room_s *copy);

#endif		/* TOOLS_LEMIN_H_ */
