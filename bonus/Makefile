## EPITECH PROJECT, 2017
## Makefile
## File description:
##makefile for the nayv
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
		SRC/my_put_color_char.c\

NAME	=	navy

CC	=	gcc -Wall -Wextra -g3 -Iinclude -lncurses

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) *#

fclean:	clean
	$(RM) $(NAME)
	$(RM) *.o

re:	fclean all

.PHONY:	fclean all re clean
