/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** By Camilleri Nathan
*/

#include <unistd.h>
#include "tools_lemin.h"

static int	my_strl(char const *str)
{
	int	index = 0;

	while (str[index] != '\0')
		index++;
	return (index);
}

void	my_putstr(int out, char const *str)
{
	write(out, str, my_strl(str));
}
