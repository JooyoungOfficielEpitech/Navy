/*
** EPITECH PROJECT, 2017
** navy
** File description:
** navy
*/

#include "../include/my.h"

char **set_my_vertical_ligne(char **board, int r, int c, int b)
{
	int s = r;

	while (r != 0) {
		board[c][b] = s + 48;
		r = r - 1;
		c = c + 1;
	}
	return board;
}

char **set_my_horizontal_ligne(char **board, int r, int c, int b)
{
	int s = r;

	while (r != 0) {
		board[c][b] = s + 48;
		r = r - 1;
		b = b + 2;
	}
	return board;
}

int set_my_shot(char **my_board, char **enemy, char **hide_board, int pid)
{
	if (print_board(my_board, enemy, hide_board, pid) == 0) {
		my_putstr(": missed\n\n");
		return 0;
	}
	else
		my_putstr(": hit\n\n");
	return 1;
}

int set_his_shot(char **my_board, int myboat)
{
	my_putstr("waiting for enemy's attack...\n");
	myboat = myboat - receive_shot(my_board);
	return myboat;
}