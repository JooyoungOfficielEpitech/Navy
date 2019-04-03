/*
** EPITECH PROJECT, 2018
** .h for the navy
** File description:
** navy
*/

#ifndef NAVY_H
#define NAVY_H

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

typedef struct ingame_s {
	int my_boat;
	int en_boat;
	char **en_map;
	char **my_map;
}ingame_t;

int player1(char *name, int pid);
int player2(char *name, int pid, int pid_en);
char *get_msg(void);
char *get_map(void);
int send_signal(int pid, char *shut);
void send_map(int pid, char *name);
ingame_t *set_game(char *map);
int my_turn(int pid, ingame_t *game);
int en_turn(int pid, ingame_t *game);
void ship_is_boom(ingame_t *game, char *msg, char type);
int check_winner(int ennemy_boat, ingame_t *game);
void my_put_color_char(char a);

#endif
