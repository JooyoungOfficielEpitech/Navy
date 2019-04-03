/*
** EPITECH PROJECT, 2018
** player2.c
** File description:
** player2
*/

#include "my.h"
#include "navy.h"

int i;

void send_connection(int sig, siginfo_t *info, void *nu)
{
	(void) nu;
	(void) sig;
	(void) info;
	my_putstr("successfully connected\n\n");
	i = 1;
}

void waiting_server(void)
{
	struct sigaction sa;

	sa.sa_sigaction = send_connection;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	i = 0;
	while (i == 0)
		sigaction(SIGUSR1, &sa, NULL);
}

int player2(char *name, int pid, int pid_en)
{
	char *my_map = read_file(name);

	if (check_error_map1(my_map, my_map) == -1) {
		my_putstr("Invalide format of the map\n");
		return (84);
	}
	my_putstr("my_pid: ");
	my_put_nbr(pid);
	my_putstr("\n");
	kill(pid_en, SIGUSR1);
	waiting_server();
	return navy(pid_en, my_map, 1);
}
