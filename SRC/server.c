/*
** EPITECH PROJECT, 2018
** server.c
** File description:
** this can open and join server
*/

#include "../include/my.h"

int i = 0;
int j = 0;

void server(int sig, siginfo_t *info, void *hi)
{
	(void)hi;
	kill(info->si_pid, sig);
	i = 1;
}
int create_server(void);
{
	struct sigaction sa;

	sa.sa_sigaction = server;
	sa.sa_flags = SA_SIGINFO;
	my_putstr("pid = ");
	my_put_nbr(getpid());
	my_putstr("\nwaiting for ennemy connection...\n");

	while (i == 0) {
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	my_putstr("Success\n");
	return (0);
}
void player(int sig, siginfo_t *info, void *hi)
{
	(void)hi;
	(void)info;
	(void)sig;
	j = 1;
}
int join_server(int pid)
{
	struct sigaction sa;

	kill(pid, SIGUSR1);
	sa.sa_sigaction = player;
	sa.sa_flags = SA_SIGINFO;

	while (j == 0) {
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	my_putstr("Success\n");
	return (0);
}
