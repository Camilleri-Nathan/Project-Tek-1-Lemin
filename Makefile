##
## EPITECH PROJECT, 2017
## Makefile Principal
## File description:
## By Camilleri Nathan
##

CC		=	gcc

RM		=	rm -f

OBJS		=	$(addprefix $(SRCDIR), $(SRCS:.c=.o))

SRCDIR		=	src/

MAKE		=	make -C

CFLAGS		=	-W -Wall -Wextra
CFLAGS		+=	-I./include/

NAME		=	lem_in

SRCS		=	tools/my_strncmp.c		\
			tools/my_putstr.c		\
			tools/my_strlen.c		\
			tools/get_next_line.c		\
			tools/my_getnbr.c		\
			tools/my_int_to_str.c		\
			tools/my_revstr.c		\
			tools/my_strcpy.c		\
			tools/my_str_isnum.c		\
			tools/my_realloc_strcat.c	\
			tools/my_put_nbr.c		\
			tools/my_putchar.c		\
			tools/useful.c			\
			tools/my_strcmp.c		\
			init/init_room.c		\
			init/take_value.c		\
			init/make_path.c		\
			init/set_path.c			\
			init/error_map.c		\
			init/test_error_part_2.c	\
			init/counter.c			\
			find_way/find_way.c		\
			main.c

DEBUG		=	no

ifeq ($(DEBUG),yes)
CFLAGS		+= -g
else
CFLAGS		+= -Werror
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lncurses

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
