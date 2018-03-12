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

int	change_line(int *carac, int *readed, char *buffer, char *line)
{
	int size = 0;

	while (size != *readed) {
		if (buffer[size] == '\n') {
			line[*carac] = '\0';
			size += 1;
			return (size);
		}
		line[*carac] = buffer[size];
		*carac += 1;
		size += 1;
	}
	line[*carac] = '\0';
	return (size);
}

char	*make_line(int fd, char *buffer, int *size, int *readed)
{
	char *line = NULL;
	int nb = 1;
	int carac = 0;

	line = malloc(sizeof(char *) * (READ_SIZE + 1));
	while (1) {
		*size = change_line(&carac, readed, buffer, line);
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
