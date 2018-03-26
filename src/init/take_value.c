/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** take_value.c
*/

#include "struct.h"
#include "init_lemin.h"
#include <stdlib.h>

char	*take_name(char *line)
{
	int carac = 0;
	char *name = NULL;

	while (line[carac] != ' ' && line[carac] != '\0') {
		carac += 1;
	}
	name = malloc(sizeof(char) * (carac + 1));
	carac = 0;
	while (line[carac] != ' ' && line[carac] != '\0') {
		name[carac] = line[carac];
		carac += 1;
	}
	name[carac] = '\0';
	return (name);
}
