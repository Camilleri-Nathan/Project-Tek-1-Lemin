/*
** EPITECH PROJECT, 2017
** my_realloc_strcat.c
** File description:
** By Camilleri Nathan
*/

#include <stdlib.h>
#include "tools_lemin.h"

char	*my_realloc_strcat(char *dest, char *src)
{
	int	index1 = 0;
	int	index2 = 0;
	char	*tmp = malloc(sizeof(char) *
	(my_strlen(dest) + my_strlen(src) + 1));

	my_strcpy(tmp, dest);
	while (tmp[index1] != '\0')
		index1 += 1;
	while (src[index2] != '\0') {
		tmp[index1] = src[index2];
		index1 += 1;
		index2 += 1;
	}
	tmp[index1] = '\0';
	return (tmp);
}
