/*
** EPITECH PROJECT, 2018
** connection test
** File description:
** test
*/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "navy.h"
#include "my.h"

int correct_msg(char *str)
{
	if (my_strlen(str) != 2) {
		my_putstr("Too long message\n");
		return (-1);
	}
	if (str[0] <= 64 || str[0] >= 73) {
		my_putstr("wrong position\n");
		return (-1);
	}
	if (str[1] <= 48 || str[1] >= 57) {
		my_putstr("wrong position\n");
		return (-1);
	}
	return (0);
}
int send_signal(int pid, char *shut)
{
	char *msg = shut;
	int one = msg[0] - 64;
	int two = msg[1] - 48;

	if (correct_msg(shut) == -1)
		return (84);
	while (one != 0) {
		kill(pid, SIGUSR1);
		usleep(10);
		one--;
	}
	while (two != 0) {
		kill(pid, SIGUSR2);
		usleep(10);
		two--;
	}
	return (1);
}
