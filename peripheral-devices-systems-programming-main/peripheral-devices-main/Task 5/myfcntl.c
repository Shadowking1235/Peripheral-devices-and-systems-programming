#include <stdio.h>
#include <fcntl.h>
main()
{
    int fd;
    fd = open("test.txt", O_WRONLY); 
    write(fd, "hi there\n", 9);
    lseek(fd, 0, SEEK_SET);                  
    fcntl(fd, F_SETFL, O_WRONLY | O_APPEND); 
    write(fd, " guys\n", 6);
    close(fd);
}

/* test.txt -> here are the contents of the original file.
$ cat test.txt 
$ ./myfcntl
$ cat test.txt 
*/