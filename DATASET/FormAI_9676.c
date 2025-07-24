//FormAI DATASET v1.0 Category: Task Scheduler ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int task1() {
    printf("Task #1 executed\n");
    return 0;
}

int task2() {
    printf("Task #2 executed\n");
    return 0;
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Schedule task #1
    int task1_delay = rand() % 10 + 1; // Random delay between 1 and 10 seconds
    printf("Task #1 scheduled in %d seconds\n", task1_delay);
    sleep(task1_delay);
    task1();

    // Schedule task #2
    int task2_delay = rand() % 10 + 1; // Random delay between 1 and 10 seconds
    printf("Task #2 scheduled in %d seconds\n", task2_delay);
    sleep(task2_delay);
    task2();

    return 0;
}