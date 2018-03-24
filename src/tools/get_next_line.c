/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** contain get_next_line.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char	*my_realloc(char *line, int nb)
{
	char *tmp = line;
	int carac = 0;

	line = malloc(sizeof(char *) * ((READ_SIZE * nb) + 1));
	if (line == NULL) {
		return (NULL);
	}
	while (tmp[carac] != '\0') {
		line[carac] = tmp[carac];
		carac += 1;
	}
	free(tmp);
	return (line);
}

void	change_line(int vector[2], int *readed, char *buffer, char *line)
{
	while (vector[1] != *readed) {
		if (buffer[vector[1]] == '\n') {
			line[vector[0]] = '\0';
			vector[1] += 1;
			return;
		}
		line[vector[0]] = buffer[vector[1]];
		vector[0] += 1;
		vector[1] += 1;
	}
	line[vector[0]] = '\0';
	return;
}

char	*make_line(int fd, char *buffer, int *size, int *readed)
{
	char *line = NULL;
	int nb = 1;
	int carac = 0;
	int vector[2];

	line = malloc(sizeof(char *) * (READ_SIZE + 1));
	while (1) {
		vector[0] = carac;
		vector[1] = *size;
		change_line(vector, readed, buffer, line);
		carac = vector[0];
		*size = vector[1];
		if (buffer[*size - 1] == '\n')
			return (line);
		*size = 0;
		*readed = read(fd, buffer, READ_SIZE);
		if (*readed == 0)
			return (line);
		nb += 1;
		line = my_realloc(line, nb);
	}
}

char	*get_next_line(int fd)
{
	static char buffer[READ_SIZE] = "";
	static int readed = 0;
	static int size = 0;
	char *line = NULL;

	if (size == readed) {
		readed = read(fd, buffer, READ_SIZE);
		if (readed == 0)
			return (NULL);
		size = 0;
	}
	line = make_line(fd, buffer, &size, &readed);
	return (line);
}
