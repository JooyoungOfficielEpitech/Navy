##
## EPITECH PROJECT, 2018
## tetris
## File description:
## Makefile of the project.
##

SRC	=	SRC/navy.c		\
		SRC/create_board.c	\
		SRC/print.c		\
		SRC/gnl.c		\
		SRC/check.c		\
		SRC/player1.c		\
		SRC/player2.c		\
		SRC/my_put_nbr.c	\
		SRC/get_msg.c		\
		SRC/connection.c	\
		SRC/read_file.c		\
		SRC/my_get_nbr.c	\
		SRC/map_maker.c		\
		SRC/set_my_game.c	\
		SRC/set_game.c		\
		SRC/turn.c	\
		SRC/ship_is_boom.c	\

OBJ	=	$(SRC:.c=.o)

MAKE := make

CC	=	gcc

CPPFLAGS	= -Iinclude/

CFLAGS	=	-Wall -Wextra -g3

LDFLAGS =

NAME	=	navy

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

tests: re
	$(MAKE) fclean -C ./tests/
	$(MAKE) -C ./tests/
	$(MAKE) run -C ./tests/
	$(MAKE) clean -C ./tests/

clean:
	rm -rf $(OBJ)

fclean:	clean
	$(MAKE) -C ./tests/ fclean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean tests fclean re
