/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** Duplicate a string.
*/

#include <stdlib.h>
#include "tools_lemin.h"

char	*my_strdup(char const *str)
{
	char	*cpy;
	int	str_len;
	int	index;

	index = 0;
	str_len = my_strlen(str);
	cpy = malloc(sizeof(char) * str_len + 1);
	if (cpy == NULL) {
		return (NULL);
	}
	while (str[index] != '\0') {
		cpy[index] = str[index];
		index = index + 1;
	}
	cpy[index] = '\0';
	return (cpy);
}
