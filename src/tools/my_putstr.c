/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** By Camilleri Nathan
*/

#include <unistd.h>
#include "tools_lemin.h"

void	my_putstr(int out, char const *str)
{
	write(out, str, my_strlen(str));
}
