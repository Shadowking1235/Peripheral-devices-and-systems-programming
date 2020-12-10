#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

main()
{
    int flag;
    flag = chmod("test.txt", 0600);
    if (flag == -1)
        perror("mychmod.c");
}

/*
$ ls -lG test.txt
$ ./mychmod
$ ls -lG test.txt
*/