/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** By Camilleri Nathan
*/

#include "tetris.h"

char	*my_strcpy(char *dest, char const *src)
{
	int	i = 0;

	while (src[i] != '\0')	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
