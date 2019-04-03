##
## EPITECH PROJECT, 2018
## makefiletest
## File description:
## ubit
##

CC := gcc
CPPFLAGS += -I../include/ --coverage
CFLAGS += -Wall -Wextra -pedantic -std=gnu11
LDFLAGS += -lcriterion --coverage

NAME = tests

SRCS =	my_get_nbr.c		\
	read_file.c		\
	../SRC/my_get_nbr.c	\
	../SRC/read_file.c	\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(NAME)

run:
	@ ./$(NAME) --verbose

rm_gcov:
	rm -rf ../SRC/utils/*.gc*
	rm -rf ../SRC/*.gc*
	rm -rf *.gc*

clean:
	$(RM) $(OBJS)


fclean: clean rm_gcov
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean run re
