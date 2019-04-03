/*
** EPITECH PROJECT, 2018
** make map
** File description:
** map
*/

#include "../include/my.h"

char *map_maker(char *map, int enter, int i)
{
	if (enter == 1 || enter == 3 || enter == 5 || enter == 7) {
		map[i] = '\n';
		map[i + 1] = '\0';
	}
	else
		map[i] = '\0';
	return (map);
}
