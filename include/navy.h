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

#endif
