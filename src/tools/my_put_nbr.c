/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** By Camilleri Nathan
*/

#include <unistd.h>
#include "tools_lemin.h"

void	my_put_nbr(int nb);

int	condition_put_nbr(int nb)
{
	int	modi;

	if (nb >= 0) {
		if (nb >= 10) {
			modi = (nb % 10);
			nb = (nb - modi) / 10;
			my_put_nbr(nb);
			my_putchar(48 + modi);
		}
		else
			my_putchar(48 + nb % 10);
	}
	return (0);
}

void	my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = nb * (-1);
	}
	condition_put_nbr(nb);
}
