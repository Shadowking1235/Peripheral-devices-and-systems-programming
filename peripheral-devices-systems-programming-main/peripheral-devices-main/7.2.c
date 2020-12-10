#define FALSE 0
#define TRUE 1
#define N 2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int turn;
int interested[N];
int await = 2;

void enter_region(int process)
{
    int other;
    other = 1 - process;
    interested[process] = TRUE;
    turn = process;
    while (turn == process && interested[other] == TRUE);
}
void leave_region(int process)
{
    printf("Process %d has left the critical section\n", process);
    interested[process] = FALSE;
}

void *func(void *id)
{
    int process = (int *)id;
    printf("Process %d has entered the thread\n", process);

    enter_region(process);

    printf("Process %d has entered the critical section. Leaving in %d s\n", process, await);

    sleep(await);

    leave_region(process);
}

int main()
{
    setbuf(stdout, NULL);
    printf("The program is running\n");
    pthread_t pr1, pr2;
    pthread_create(&pr1, NULL, func, (void *)0);
    pthread_create(&pr2, NULL, func, (void *)1);
    pthread_join(pr1, NULL);
    pthread_join(pr2, NULL);
    printf("Execution is finished\n");
    return 0;
}