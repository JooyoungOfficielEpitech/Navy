#include "my.h"
#include "navy.h"
#include "criterion/criterion.h"

Test(my_get_nbr, positif) {
	cr_assert(my_get_nbr("5") == 5);
}

Test(my_get_nbr, negatif) {
	cr_assert(my_get_nbr("-5") == -5);
}
