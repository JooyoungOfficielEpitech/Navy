/*
** EPITECH PROJECT, 2018
** turn.c
** File description:
** can role into the turn of each players
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "get_next_line.h"

static int check_the_shot(char **my_board, char *shot)
{
	int a = 0;
	int b = 0;

	while (my_board[0][b] != shot[0])
		b = b + 1;
	while (my_board[a][0] != shot[1])
		a = a + 1;
	if (my_board[a][b] == '.')
		return 2;
	else if (my_board[a][b] == 'x' || my_board[a][b] == 'o')
		return 1;
	return (3);
}

int resend(ingame_t *game, char *msg)
{
	int check = check_the_shot(game->my_map, msg);

	if (check == 1)
		return (1);
	else if (check == 2)
		return (2);
	else
		return (3);
}

int my_turn(int pid, ingame_t *game)
{
	char *msg;
	char *check;

	my_putstr("attack: ");
	msg = get_next_line(0);
	if (msg == NULL)
		return (99);
	if (check_error_shot(msg) == -1) {
		my_putstr("Invalid format of shot\n");
		if (my_turn(pid, game) == 99)
			return (99);
	}
	send_signal(pid, msg);
	check = get_msg();
	if (check[0] == 'A') {
		my_putstr("Already shot\n");
		my_turn(pid, game);
	}
	else if (check[0] == 'C') {
		ship_is_boom(game, msg, 'x');
		return (1);
	}
	else {
		ship_is_boom(game, msg, 'o');
		return (0);
	}
	return (7);
}

static int modify_my_map(ingame_t *game, char *msg)
{
	int a = 0;
	int b = 0;

	while (game->my_map[0][b] != msg[0])
		b = b + 1;
	while (game->my_map[a][0] != msg[1])
		a = a + 1;
	if (game->my_map[a][b] == '.') {
		game->my_map[a][b] = 'o';
		return 0;
	}
	else
		game->my_map[a][b] = 'x';
	return 1;
}

int en_turn(int pid, ingame_t *game)
{
	char *msg;
	int re;

	my_putstr("waiting for ennemy's attack...\n");
	msg = get_msg();
	my_putstr(msg);
	re = resend(game, msg);
	if (re == 1)
		send_signal(pid, "A1");
	else if (re == 2) {
		my_putstr(" : missed\n\n");
		send_signal(pid, "B1");
	}
	else {
		my_putstr(" : hit\n\n");
		send_signal(pid, "C1");
	}
	if (re == 1)
		en_turn(pid, game);
	return (modify_my_map(game, msg));
}
