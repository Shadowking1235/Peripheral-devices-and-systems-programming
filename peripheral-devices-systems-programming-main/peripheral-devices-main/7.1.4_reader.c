#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

main ()
{ 
	int fd;
	char str[100];
	mkfifo("aPipe", 0660);
	fd = open("aPipe", O_RDONLY);
	while(readLine (fd, str))
		printf("%s\n", str);
	close(fd);
}

/* readLine(fd, str) int fd; char* str; */
readLine(int fd, char* str)
{ 
	int n;
	do
	{
		n = read(fd, str, 1);
	}
	while(n > 0 && *str++ != 0);
	return(n > 0);
}