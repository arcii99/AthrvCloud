//FormAI DATASET v1.0 Category: Task Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Define the tasks to be scheduled
void task1() {
    printf("Task 1 executed.\n");
}

void task2() {
    printf("Task 2 executed.\n");
}

void task3() {
    printf("Task 3 executed.\n");
}

int main() {
    // Define the time intervals for each task
    int interval1 = 3;
    int interval2 = 5;
    int interval3 = 2;

    // Define the signal handlers for each task
    signal(SIGALRM, task1);
    signal(SIGUSR1, task2);
    signal(SIGUSR2, task3);

    // Set up the timer for each task interval
    ualarm(interval1 * 1000000, interval1 * 1000000);
    ualarm(interval2 * 1000000, interval2 * 1000000);
    ualarm(interval3 * 1000000, interval3 * 1000000);

    // Loop forever, allowing the tasks to execute as scheduled
    while (1) {
        sleep(1);
    }

    return 0;
}