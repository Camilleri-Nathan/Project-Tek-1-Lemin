/*
** EPITECH PROJECT, 2017
** my_int_to_str.c
** File description:
** By Camilleri Nathan
*/

#include <stdlib.h>

char	*my_int_to_str(int nbr, char str[10])
{
	int zero = 1;
	int carac = 0;

	while (zero < nbr) {
		zero *= 10;
	}
	zero /= 10;
	while (zero != 0) {
		str[carac] = (nbr / zero) + '0';
		nbr %= zero;
		zero /= 10;
		carac += 1;
	}
	str[carac] = '\0';
	return (str);
}
