/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** By Camilleri Nathan
*/

#include "tetris.h"

int	condition_my_getnbr(char const *str, int index, char sign)
{
	if (str[index] == '-')
		sign = sign * -1;
	return (sign);
}

int	my_getnbr(char const *str)
{
	long	nombre = 0;
	int	index = 0;
	char	sign = 1;

	while (str[index] == '-' || str[index] == '+') {
		sign = condition_my_getnbr(str, index, sign);
		index = index + 1;
	}
	while ('0' <= str[index] && str[index] <= '9') {
		nombre = nombre * 10 + (str[index] - 48);
		index = index + 1;
	}
	if (-2147483648 <= nombre && nombre <= 2147483647)
		return (nombre * sign);
	return (0);
}
