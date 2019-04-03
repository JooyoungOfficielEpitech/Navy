/*
** EPITECH PROJECT, 2017
** read_file.c
** File description:
** can use read function for read a doc file by his file name
*/

#include "../include/my.h"

int counter_char(char *name)
{
	int i = 1;
	int ret = 1;
	char buf[1];
	int fd = open(name, O_RDONLY);

	while ((ret = read(fd, buf, 1) == 1)) {
		i = i + ret;
	}

	close(fd);
	return (i - 1);
}

char *read_file(char *name)
{
	int size = counter_char(name);
	char *result = malloc(sizeof(char) * (size + 1));
	int fd = open(name, O_RDONLY);

	read(fd, result, size);
	result[size] = '\0';
	close(fd);

	return (result);
}
