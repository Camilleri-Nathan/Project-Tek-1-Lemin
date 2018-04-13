/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** print message
*/

#include "struct.h"
#include "init_lemin.h"
#include "get_next_line.h"
#include "tools_lemin.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	print_message(info_s *info)
{
	my_putstr(1, "#number_of_ants\n");
	my_put_nbr(info->ants);
	my_putchar('\n');
	my_putstr(1, "#rooms\n");
}
