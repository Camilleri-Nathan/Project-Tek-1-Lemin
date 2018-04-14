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
	char	*copy;
	int	strlen_2;
	int	index;

	index = 0;
	strlen_2 = my_strlen(str);
	copy = malloc(sizeof(char) * stren_2 + 1);
	if (copy == NULL) {
		return (NULL);
	}
	while (str[index] != '\0') {
		copy[index] = str[index];
		index = index + 1;
	}
	copy[index] = '\0';
	return (copy);
}
