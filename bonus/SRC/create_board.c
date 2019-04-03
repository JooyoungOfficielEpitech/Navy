/*
** EPITECH PROJECT, 2017
** navy
** File description:
** navy
*/

#include "../include/my.h"
#include "../include/navy.h"

char **create_my_board(char *pos, int a, int c, int b)
{
	int k = 2;
	char **enemy = create_enemy_board();

	while (k != 6) {
		b = find_the_letter(pos[a], enemy, 1);
		a = a + 1;
		c = find_the_letter(pos[a], enemy, 0);
		if (enemy[c][b] != '.')
			return NULL;
		enemy[c][b] = k + 48;
		if (pos[a + 2] == pos[a - 1])
			enemy = set_my_vertical_ligne(enemy, k, c, b);
		else
			enemy = set_my_horizontal_ligne(enemy, k, c, b);
		k = k + 1;
		b = 0;
		a = a + 7;
		c = 0;
	}
	return enemy;
}

int find_the_letter(char pos, char **enemy, int a)
{
	int b = 0;
	if (a == 1) {
		while (pos != enemy[0][b])
			b = b + 1;
	}
	else {
		while (pos != enemy[b][0])
			b = b + 1;
	}
	return b;
}

char **create_enemy_board(void)
{
	int b = 0;
	char **board = malloc(sizeof(char *) * (11));

	for (b = 0; b < 11; b = b + 1)
		board[b] = malloc(sizeof(char) * (20));
	my_strcpy(board[0], " |A B C D E F G H");
	my_strcpy(board[1], "-+---------------");
	my_strcpy(board[2], "1|. . . . . . . .");
	my_strcpy(board[3], "2|. . . . . . . .");
	my_strcpy(board[4], "3|. . . . . . . .");
	my_strcpy(board[5], "4|. . . . . . . .");
	my_strcpy(board[6], "5|. . . . . . . .");
	my_strcpy(board[7], "6|. . . . . . . .");
	my_strcpy(board[8], "7|. . . . . . . .");
	my_strcpy(board[9], "8|. . . . . . . .");
	return board;
}

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int navy(int pid, char *buff, int turn)
{
	ingame_t *game = set_game(buff);
	static int printer = 0;

	if (game->my_map == NULL)
		return 84;
	print_board2(game->my_map, game->en_map);
	while (game->my_boat != 0 && game->en_boat != 0) {
		if (turn % 2 == 0) {
			game->en_boat -= my_turn(pid, game);
			if (game->en_boat <= -50)
				return (0);
		}
		else
			game->my_boat -= en_turn(pid, game);
		turn = turn + 1;
		printer++;
		if (printer == 2) {
			print_board2(game->my_map, game->en_map);
			printer = 0;
		}
	}
	return check_winner(game->en_boat, game);
}
