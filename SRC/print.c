/*
** EPITECH PROJECT, 2017
** navy
** File description:
** navy
*/

#include "../include/my.h"
#include "get_next_line.h"

int printtabl(char **rts, int cln, int lin)
{
	int i = 0;
	int a = 0;

	while (i < lin) {
		a = 0;
		while (a < cln) {
			my_putchar(rts[i][a]);
			a++;
		}
		my_putchar('\n');
		i++;
	}
	return 0;
}

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_putstr(char const *str)
{
	int z = 0;

	while (str[z] != '\0') {
		my_putchar(str[z]);
		z++;
	}
	return 0;
}

int print_board(char **my_board, char **enemy, char **hide_board, int pid)
{
	char *shot = NULL;
	char *check;

	my_putstr("attack:	");
	shot = get_next_line(0);
	while (shot == NULL) {
		my_putstr("wrong position\nattack: ");
		shot = get_next_line(0);
	}
	my_putstr(shot);
	send_signal(pid, shot);
	check = get_msg();
	if (check[0] == 'B') {
		my_putstr(": hit\n\n");
		return (1);
	}
	else if (check[0] == 'A') {
		my_putstr(": Already shot\n");
		print_board(my_board, enemy, hide_board, pid);
	}
	else
		my_putstr(": missed\n\n");
	return 0;
}

void print_board2(char **my_board, char **enemy)
{
	my_putstr("my positions:\n");
	printtabl(my_board, 17, 10);
	my_putchar('\n');
	my_putstr("enemy's positions:\n");
	printtabl(enemy, 17, 10);
	my_putchar('\n');
}
