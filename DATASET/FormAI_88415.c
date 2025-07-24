//FormAI DATASET v1.0 Category: Task Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef void (*TaskFunction)(void);

typedef struct {
    int interval;
    int remaining_time;
    TaskFunction task;
} Task;

void task1() {
    printf("I'm task 1!\n");
}

void task2() {
    printf("I'm task 2!\n");
}

int main() {
    Task tasks[2] = {
        {3, 3, &task1},
        {5, 5, &task2}
    };
    int num_tasks = sizeof(tasks) / sizeof(tasks[0]);

    while (1) {
        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].remaining_time == 0) {
                tasks[i].task();
                tasks[i].remaining_time = tasks[i].interval;
            } else {
                tasks[i].remaining_time--;
            }
        }
        usleep(100000); // sleep for 100ms
    }

    return 0;
}