/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** a
*/

#ifndef MY_H_
# define MY_H_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

char **create_enemy_board();
int printtabl(char **rts, int cln, int lin);
int navy(int pid, char *buff, int turn);
int check_error_map2(char *pos1);
void my_putchar(char c);
int check_error_map1(char *pos1, char *pos2);
void print_board2(char **my_board, char **enemy);
char **set_my_horizontal_ligne(char **board, int r, int c, int b);
char **create_my_board(char *pos, int a, int c , int b);
int set_my_shot(char **my_board, char **enemy, char **hide_board, int pid);
int set_his_shot(char **my_board, int myboat);
int player1(char *name, int pid);
int player2(char *name, int pid, int pid_en);
int find_the_letter(char pos, char **enemy, int a);
char *get_msg(void);
char *get_map(void);
int send_signal(int pid, char *shut);
void send_map(int pid, char *name);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(const char *str);
int receive_shot(char **my_board);
char *read_file(char *name);
int my_put_nbr(int nb);
char *my_strcpy(char *dest, char const *src);
char **set_my_vertical_ligne(char **board, int r, int c, int b);
char *sig_char(int one, int two);
void connection(int sig, siginfo_t *info, void *mam);
char *get_msg(void);
int check_error_shot(char *shot);
int my_putstr(char const *str);
char *pick_my_map(char *map);
char pick_my_char(int fd);
char *resize_my_str(char *str, char c, int i);
char* my_realloc(char *src, int len);
int create_server();
int join_server(int pid);
int my_strlen(char const *str);
int send_signal(int pid, char *shut);
void send_map(int pid, char *name);
char *get_map();
char *read_file(char *name);
int check_my_shot(char **hide_board, char *shot, char **enemy);
int check_his_shot(char **my_board, char *shot);
int print_board(char **my_board, char **enemy, char **hide_board, int pid);
int my_get_nbr(char const *str);
char *map_maker(char *map, int enter, int i);

#endif
