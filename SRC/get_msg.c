/*
** EPITECH PROJECT, 2018
** testing connextion
** File description:
** yes
*/

#include <fcntl.h>
#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/types.h>
#include "navy.h"
#include "my.h"

char *msg;

char *sig_char(int one, int two)
{
	char *ret = malloc(sizeof(char) * 3);

	ret[0] = '@';
	ret[1] = '0';
	ret[2] = '\0';

	while (one != 0) {
		ret[0]++;
		one--;
	}
	while (two != 0) {
		ret[1]++;
		two--;
	}
	return (ret);
}

void connection(int sig, siginfo_t *info, void *mam)
{
	static int one = 0;
	static int two = 0;

	(void) info;
	(void) mam;
	if (msg[0] == '@' && msg[1] == '0') {
		one = 0;
		two = 0;
	}
	if (sig == SIGUSR1)
		one++;
	if (sig == SIGUSR2)
		two++;
	msg = sig_char(one, two);
}

char *get_msg(void)
{
	struct sigaction sa;
	float i = 0;

	msg = malloc(sizeof(char) * 3);
	msg[0] = '@';
	msg[1] = '0';
	msg[2] = '\0';
	sa.sa_sigaction = connection;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	while (i <= 999999) {
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		if (msg[0] != '@')
			i++;
	}
	return (msg);
}
