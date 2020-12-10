#include <unistd.h>

main()
{
    link("original.txt", "another.txt");
}

/* original.txt -> this is a file
$ cat original.txt 
$ ls -lG original.txt another.txt -> not found
$ ./mylink
$ ls -lG original.txt another.txt
$ cat >> another.txt 
$ ls -lG original.txt another.txt
$ rm original.txt
$ ls -lG original.txt another.txt 
$ cat another.txt
*/
