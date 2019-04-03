/*
** EPITECH PROJECT, 2018
** test
** File description:
** read
*/

#include "criterion/criterion.h"
#include "navy.h"
#include "my.h"

Test(read_file, normal) {
	cr_assert(read_file("read_test.txt")[0] = 'e');
}
