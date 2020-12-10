#include <stdio.h>

main (int argc, char* argv[])
{ 
	if (fork() == 0)
	{
		execvp(argv[1], &argv[1]);
		fprintf(stderr, "Could not execute %s\n", argv[1]);
	}
}

/*
$ background sleep 60 ...выполнить программу. background - имя этого файла, sleep - вызываемый метод
$ ps ...подтвердить, что сс работает в фоне.
*/
