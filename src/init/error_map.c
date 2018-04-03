/*
** EPITECH PROJECT, 2018
** lem in
** File description:
** manage the error
*/

#include "struct.h"
#include "init_lemin.h"
#include "tools_lemin.h"
#include "get_next_line.h"
#include <stdlib.h>

#include <stdio.h>

int	check_nb_start(info_s *info)
{
	int index = 0;
	int check_start = 0;

	while (info->path[index] != NULL) {
		if (!my_strcmp(info->path[index], "##start")) {
			check_start += 1;
			printf("tt\n");
		}
		index++;
	}
	return (check_start);
}

int	test_error(info_s *info)
{
	int check_start = 0;
//	int check_end = 1;

//	printf("check_start = %d\n", check_start);
	check_start = check_nb_start(info);
	if (check_start != 1) {
		printf("toto");
		return (84);
	}
	printf("tata\n");
	return (0);
}
