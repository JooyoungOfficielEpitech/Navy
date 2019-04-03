/*
** EPITECH PROJECT, 2017
** navy
** File description:
** navy
*/

#include "../include/my.h"

int check_my_shot(char **hide_board, char *shot, char **enemy)
{
	int a = 0;
	int b = 0;

	while (enemy[0][b] != shot[0])
		b = b + 1;
	while (enemy[a][0] != shot[1])
		a = a + 1;
	if (hide_board[a][b] == '.') {
		enemy[a][b] = 'o';
		return 0;
	}
	else if (hide_board[a][b] == 'x')
		return 2;
	else {
		enemy[a][b] = 'x';
		hide_board[a][b] = 'x';
		return 1;
	}
}

int check_his_shot(char **my_board, char *shot)
{
	int a = 0;
	int b = 0;

	while (my_board[0][b] != shot[0])
		b = b + 1;
	while (my_board[a][0] != shot[1])
		a = a + 1;
	if (my_board[a][b] == '.') {
		my_board[a][b] = 'o';
		return 0;
	}
	else
		my_board[a][b] = 'x';
	return 1;
}

int check_error_map1(char *pos1, char *pos2)
{
	int a = 0;
	int b = 2;

	while (a != 32) {
		if (pos1[a] != b + 48)
			return -1;
		if (pos1[a + 1] != ':' || pos1[a + 4] != ':')
			return -1;
		if (pos1[a + 2] < 'A' || pos1[a + 2] > 'H' ||
		pos1[a + 5] < 'A' || pos1[a + 5] > 'H')
			return - 1;
		if (pos1[a + 3] < '1' || pos1[a + 3] > '8' ||
		pos1[a + 6] < '1' || pos1[a + 6] > '8')
			return -1;
		if (pos1[a + 7] != '\n' && pos1[a + 7] != '\0')
			return -1;
		a = a + 8;
		b = b + 1;
	}
	return check_error_map2(pos2);
}

int check_error_map2(char *pos1)
{
	int a = 0;
	int b = 2;

	while (a != 32) {
		if (pos1[a] != b + 48)
			return -1;
		if (pos1[a + 1] != ':' || pos1[a + 4] != ':')
			return -1;
		if (pos1[a + 2] < 'A' || pos1[a + 2] > 'H' ||
		pos1[a + 5] < 'A' || pos1[a + 5] > 'H')
			return - 1;
		if (pos1[a + 3] < '1' || pos1[a + 3] > '8' ||
		pos1[a + 6] < '1' || pos1[a + 6] > '8')
			return -1;
		if (pos1[a + 7] != '\n' && pos1[a + 7] != '\0')
			return -1;
		a = a + 8;
		b = b + 1;
	}
	return 0;
}

int check_error_shot(char *shot)
{
	if (shot[0] < 'A' || shot[0] > 'H')
		return -1;
	if (shot[1] < '1' || shot[1] > '8')
		return -1;
	if (shot[2] != '\0' && shot[2] != '\n')
		return -1;
	return 0;
}