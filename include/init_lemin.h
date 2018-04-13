/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** init lemin
*/

#ifndef	INIT_LEMIN_H_
#define	INIT_LEMIN_H_

// ___ init_room.c ___

room_s	*set_room(room_s *room, info_s *info);
int	set_ants(info_s *info);
int	set_point(info_s *info, char *line);
char	*fill_point(info_s *info);
room_s	**make_room(info_s *info);
void	print_message(info_s *info);
void	copy_array_in_make_room(info_s *info, int tab, int array,
				room_s **copy);
void	end_of_fill_point(char *line, int *caract, char *point);

// ___ take_value.c ___

int	init_room(info_s *info);
char	*take_name(char *line);
char	*take_first(char *str);
char	*take_second(char *str);

// ___ make_path.c ___

void	set_path(room_s *room, room_s **copy, info_s *info);
room_s	*link_path_create(path_s *path, room_s *room, room_s **copy,
info_s *info);
void	save_path(info_s *info, char *line);
char	**realloc_path(char **path, int *array, info_s *info);
char	**make_copy(char **path, info_s *info);

// ___ set_path.c ___

room_s	*link_path(room_s *room, room_s **copy, info_s *info);
room_s	*add_room(char *line);
void	make_path(room_s *room, room_s *save);
void	link_room(info_s *info, room_s *room, room_s **copy);
void	add_link(char *first, char *second, room_s *room, room_s *copy);

// **** error_file ******

int	test_link_first(info_s *info);
int	test_error(info_s *info);
int	check_after_start_and_end(info_s *info);
int	check_nb_av_and_type(info_s *info);
int	check_hyphen_file(info_s *info);
int	counter_space(char *str);
int	counter_hyphen(char *str);

// **** send_ant ******

int	send_and_display_ant(info_s info, path_s path);

#endif		/* TOOLS_LEMIN_H_ */
