//FormAI DATASET v1.0 Category: Task Scheduler ; Style: expert-level
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>

void task_a() {
    printf("Executing Task A\n");
}

void task_b() {
    printf("Executing Task B\n");
}

void task_c() {
    printf("Executing Task C\n");
}

int main() {

    struct itimerval timer;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 2;
    timer.it_interval.tv_usec = 0;

    signal(SIGALRM, (void (*) (int)) task_a);
    setitimer(ITIMER_REAL, &timer, NULL);

    signal(SIGALRM, (void (*) (int)) task_b);
    setitimer(ITIMER_REAL, &timer, NULL);

    signal(SIGALRM, (void (*) (int)) task_c);
    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        pause();
    }

    return 0;
}