/*
** EPITECH PROJECT, 2017
** my_strncmp.c
** File description:
** By Camilleri Nathan
*/

int	my_strncmp(char *str1, char *str2, int nb)
{
	int carac = 0;

	while (nb != 0 && str1[carac] != '\0' && str2[carac] != '\0') {
		if (str1[carac] != str2[carac])
			return (0);
		nb -= 1;
		carac += 1;
	}
	return (1);
}
