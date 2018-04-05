/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** By Camilleri Nathan
*/

int	my_strlen(char const *str)
{
	int	index = 0;

	while (str[index] != '\0') {
		index += 1;
	}
	return (index);
}
