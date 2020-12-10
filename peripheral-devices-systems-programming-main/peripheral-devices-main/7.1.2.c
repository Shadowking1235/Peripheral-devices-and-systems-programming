#include <stdio.h>
#include <fcntl.h>

main (int argc, char* argv [])
{
	int fd;
	fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0600);
	dup2(fd, 1);
	close(fd);
	execvp(argv[2], &argv[2]);
	perror("main");
}