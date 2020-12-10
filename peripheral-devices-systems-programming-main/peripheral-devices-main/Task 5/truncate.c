#include <unistd.h>

main()
{
    truncate("file1.txt", 10);
    truncate("file2.txt", 10);
}

/* file1.txt -> short; file2.txt -> long file with lots of letters
$ cat file1.txt
$ cat file2.txt
$ ls -lG file*.txt 
$ ./truncate
$ ls -lG file*.txt 
$ cat file1.txt 
$ cat file2.txt
*/