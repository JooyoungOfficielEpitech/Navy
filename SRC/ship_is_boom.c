/*
** EPITECH PROJECT, 2018
** ship_is_boom
** File description:
** bammmm
*/

#include "my.h"
#include "navy.h"

void ship_is_boom(ingame_t *game, char *msg, char type)
{
	int a = 0;
	int b = 0;

	if (type == 'x') {
		my_putstr(msg);
		my_putstr(" : hit\n\n");
	}
	else {
		my_putstr(msg);
		my_putstr(" : missed\n\n");
	}
	while (game->en_map[0][b] != msg[0])
		b++;
	while (game->en_map[a][0] != msg[1])
		a++;
	game->en_map[a][b] = type;
}
