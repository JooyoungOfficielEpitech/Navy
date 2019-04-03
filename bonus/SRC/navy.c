/*
** EPITECH PROJECT, 2017
** navy
** File description:
** navy
*/

#include "../include/my.h"
#include "navy.h"

int main(int ac, char **av)
{
	if (ac == 2)
		return (player1(av[1], getpid()));
	if (ac == 3) {
		return (player2(av[2], getpid(), my_get_nbr(av[1])));
	}
	else
		return 84;
	return 0;
}

char *pick_my_map(char *map)
{
	int file_descriptor;
	int offset = 0;
	int lenght = 0;
	char *buff = malloc(sizeof(char) * 33);

	file_descriptor = open(map, O_RDONLY);
	if (file_descriptor == -1)
		return NULL;
	while ((lenght = read(file_descriptor, buff + offset, 32 - offset)) > 0)
		offset = offset + lenght;
	return buff;
}

int receive_shot(char **my_board)
{
	char *shot = get_msg();

	if (check_his_shot(my_board, shot) == 1) {
		my_putstr(shot);
		my_putstr(": hit\n\n");
		return 1;
	}
	else {
		my_putstr(shot);
		my_putstr(": missed\n\n");
		return 0;
	}
}

int check_winner(int enemy_boat, ingame_t *game)
{
	print_board2(game->my_map, game->en_map);
	if (enemy_boat == 0) {
		my_putstr("I won\n");
		return 0;
	}
	my_putstr("Enemy won\n");
	return 1;
}

int my_strlen (char const *str)
{
	int z = 0;

	while (str[z] != '\0')
		z++;
	return z;
}
