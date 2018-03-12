/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** init_map.c
*/

#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "struct.h"

int	strlen_rooms(char *file_name)
{
	int index = 0;
	int fd = open(file_name, O_RDONLY);
	char *line = get_next_line(fd);
	
	while (line != NULL) {
		while (line[index] != '\0') {
			if (line[index] == ' ') {
				nb_room++;
				break;
			}
			index++;
		}
		index = 0;
		line = get_next_line(fd);
	}
	close(fd);
	return (nb_room);
}

int	strlen_way(char *file_name)
{
	
}

int	init_map(char *file_name, room_s *room)
{
	int fd = open(file_name, O_RDONLY);
	int nb_tt_rooms = strlen_rooms(file_name);
	char *line = get_next_line(file_name);
	
	room = malloc(sizeof(room_s) * nb_tt_rooms);
}
