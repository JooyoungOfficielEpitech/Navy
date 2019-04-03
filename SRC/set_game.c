/*
** EPITECH PROJECT, 2018
** set the gmae
** File description:
** structure
*/

#include "my.h"
#include "navy.h"

ingame_t *set_game(char *map)
{
	ingame_t *ret = malloc(sizeof(ingame_t));

	ret->my_boat = 14;
	ret->en_boat = 14;
	ret->en_map = create_enemy_board();
	ret->my_map = create_my_board(map, 2, 0, 0);
	return (ret);
}
