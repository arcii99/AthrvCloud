//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: complex
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>

volatile int counter = 0;

void timer_handler(int sig)
{
    counter++;
}

int main()
{
    struct itimerval timer;
    signal(SIGALRM, timer_handler);

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;

    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    if(setitimer(ITIMER_REAL, &timer, NULL) == -1)
    {
        printf("Error setting timer\n");
        return 1;
    }

    pid_t pid = getpid();

    while(1)
    {
        printf("CPU usage: %d %%\n", counter);
        printf("Process ID: %d\n", pid);
        sleep(2);
    }

    return 0;
}