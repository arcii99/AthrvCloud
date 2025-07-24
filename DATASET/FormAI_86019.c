//FormAI DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

#define INTERVAL 100000

void task1() {
    printf("Task 1 running...\n");
}

void task2() {
    printf("Task 2 running...\n");
}

void task3() {
    printf("Task 3 running...\n");
}

int main() {
    struct itimerval timer;
    struct sigaction sa;

    // Set up our task schedule
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = INTERVAL;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = INTERVAL;

    // Set up signal handling for SIGALRM
    sa.sa_handler = &task1;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGALRM, &sa, NULL);

    // Set up second task schedule
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = INTERVAL * 2;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = INTERVAL * 2;

    // Set up signal handling for second task
    sa.sa_handler = &task2;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGALRM, &sa, NULL);

    // Set up third task schedule
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = INTERVAL * 3;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = INTERVAL * 3;

    // Set up signal handling for third task
    sa.sa_handler = &task3;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGALRM, &sa, NULL);

    // Start the timer
    setitimer(ITIMER_REAL, &timer, NULL);

    // Loop forever, waiting for signals
    while (1) {
        sleep(1);
    }

    return 0;
}