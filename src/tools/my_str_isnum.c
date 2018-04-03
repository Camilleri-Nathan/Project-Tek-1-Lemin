/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** task11
*/

#include <unistd.h>
#include "tools_lemin.h"

int	my_str_isnum(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (84);
	}
	return (0);
}
