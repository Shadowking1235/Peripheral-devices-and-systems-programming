#include <stdio.h>
#include <fcntl.h>

main()
{ 
	int fd, messageLen, i;
	char message[100];
	sprintf(message, "Hello from PID %d", getpid());
	messageLen = strlen(message) + 1;
	do
	{
		fd = open("aPipe", 0_WRONLY);
		if (fd == -1) sleep(1);
	}
	while(fd == -1);
	for (i = 1; i <= 3; i++)
	{
		write(fd, message, messageLen);
		sleep(3);
	}
	close(fd);
}