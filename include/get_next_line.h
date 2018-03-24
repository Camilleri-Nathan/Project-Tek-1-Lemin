/*
** EPITECH PROJECT, 2018
** get_next_line.h
** File description:
** contain prototype for get_next_line
*/

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef READ_SIZE
#define READ_SIZE (69)
#endif // READ_SIZE

char	*get_next_line(int fd);
char	*my_realloc(char *line, int nb);
char	*make_line(int fd, char *buffer, int *size, int *readed);
void	change_line(int vector[2], int *readed, char *buffer, char *line);

#endif // GET_NEXT_LINE_H
