/*
** EPITECH PROJECT, 2018
** color
** File description:
** col
*/

#include "navy.h"
#include "my.h"

void my_put_color_char(char a)
{
	if (a == 'o')
		my_putstr(RED);
	if (a == 'x')
		my_putstr(GRN);
	if (a == '.')
		my_putstr(BLU);
	write(1, &a, 1);
	my_putstr(RESET);
}
