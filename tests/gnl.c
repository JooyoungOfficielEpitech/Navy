#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "criterion/criterion.h"

Test(get_next_line, normal) {
	int fd = open("test", O_RDONLY);
	char *msg = NULL;

	msg = get_next_line(fd);
	cr_assert_str_eq(msg, "hello", "Erreur sur le gnl");
}
