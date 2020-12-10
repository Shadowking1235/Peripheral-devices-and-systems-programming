#include <unistd.h>
#include <stdio.h>

main()
{
    int flag;
    flag = chown("test.txt", -1, 62);
    if (flag == -1)
        perror("mychown.c");
}

/*
$ ls -l test.txt
$ ./mychown
$ ls -l test.txt
*/