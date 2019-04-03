/*
** EPITECH PROJECT, 2018
** player1.c
** File description:
** this is a player1 interface
*/

#include "my.h"
#include "navy.h"

int i;
int pid_en;

void if_connection(int sig, siginfo_t *info, void *nu)
{
	(void) nu;
	(void) sig;
	my_putstr("enemy connected\n\n");
	kill(info->si_pid, SIGUSR1);
	pid_en = info->si_pid;
	i = 1;
}

void waiting_ennemy(void)
{
	struct sigaction sa;

	sa.sa_sigaction = if_connection;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	i = 0;
	while (i == 0) {
		sigaction(SIGUSR1, &sa, NULL);
	}
}

int player1(char *name, int pid)
{
	char *my_map = read_file(name);

	if (check_error_map1(my_map, my_map) == -1) {
		my_putstr("Invalide format of the map\n");
		return (84);
	}
	my_putstr("my_pid: ");
	my_put_nbr(pid);
	my_putstr("\nwaiting for enemy connection...\n\n");

	waiting_ennemy();
	return (navy(pid_en, my_map, 0));
}
