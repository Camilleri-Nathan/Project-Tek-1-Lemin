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

static int	verify_tunnel(char *str)
{
	unsigned int	count = 0;
	unsigned int	count2 = 0;

	while (str[count] != '-') {
		count++;
	}
	if (count == 0)
		return (-1);
	count++;
	while (str[count] != '\0') {
		count++;
		count2++;
	}
	if (count2 == 0)
		return (-1);
	return (0);
}

int	counter_hyphen(char *str)
{
	int hyphen = 0;
	int index = 0;

	if (str[0] == '#')
		return (-1);
	while (str[index] != '\0') {
		if (str[index] == '-') {
			if (verify_tunnel(str) == -1)
				return (-1);
			hyphen++;
		}
		index++;
	}
	return (hyphen);
}
