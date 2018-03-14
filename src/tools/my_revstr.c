/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** By Camilleri Nathan
*/


char	*my_revstr(char *str)
{
	int	end = 0;
	int	start = 0;
	char	c = 0;

	while (str[end + 1] != '\0') {
		end++;
	}
	while (end != start) {
		c = str[start];
		str[start] = str[end];
		str[end] = c;
		end--;
		start++;
	}
	return (str);
}
