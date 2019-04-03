#include "my.h"
#include "navy.h"
#include "criterion/criterion.h"

Test(my_strlen, normal) {
	cr_assert(my_strlen("hello") == 5);
}
