/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** counter
*/

#include "struct.h"
#include "init_lemin.h"
#include "tools_lemin.h"
#include "get_next_line.h"
#include <stdlib.h>

int	counter_space(char *str)
{
	int space = 0;
	int index = 0;

	if (str[0] == '#')
		return (-1);
	while (str[index] != '\0') {
		if (str[index] == ' ')
			space++;
		index++;
	}
	return (space);
}

int	counter_hyphen(char *str)
{
	int hyphen = 0;
	int index = 0;

	if (str[0] == '#')
		return (-1);
	while (str[index] != '\0') {
		if (str[index] == '-')
			hyphen++;
		index++;
	}
	return (hyphen);
}
