#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <sys/io.h>
#include <sys/ioctl.h>
#include <linux/kd.h>

int change()
{
    int fd;
    fd = open("/dev/tty0", O_NOCTTY);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    int state = 0;
    if (-1 == ioctl(fd, KDGKBLED, &state))
    {
        perror("ioctl");
        return -1;
    }
    state ^= K_CAPSLOCK;
    if (-1 == ioctl(fd, KDSKBLED, state))
    {
        perror("ioctl set");
        close(fd);
        return -1;
    }
    close(fd);
    return 0;
}

int main()
{
    while (1)
    {
        int t = getchar();
        switch (t)
        {
        case 10:
            change();
            break;
        default:
            break;
        }
    }
}
