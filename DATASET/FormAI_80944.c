//FormAI DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tasks_executed = 0;

void task_1() {
    printf("Executing Task 1...\n");
    sleep(1);
    printf("Task 1 complete!\n");
    tasks_executed++;
}

void task_2() {
    printf("Executing Task 2...\n");
    sleep(1);
    printf("Task 2 complete!\n");
    tasks_executed++;
}

void task_3() {
    printf("Executing Task 3...\n");
    sleep(1);
    printf("Task 3 complete!\n");
    tasks_executed++;
}

int main() {
    printf("Starting Task Scheduler...\n");

    //set seed for random number generation
    srand(time(NULL));

    while (tasks_executed < 10) {
        int r = rand() % 3 + 1; //generate a random number between 1-3
        if (r == 1) {
            task_1();
        } else if (r == 2) {
            task_2();
        } else {
            task_3();
        }
    }

    printf("All tasks complete! Exiting Task Scheduler...\n");

    return 0;
}