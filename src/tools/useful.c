/*
** EPITECH PROJECT, 2018
** useful.c
** File description:
** contain useful function
*/

int	find_arrow(char *str)
{
	int carac = 0;

	while (str[carac] != '\0') {
		if (str[carac] == '-')
			return (1);
		carac += 1;
	}
	return (0);
}
