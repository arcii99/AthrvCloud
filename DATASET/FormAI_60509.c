//FormAI DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int interval;
    time_t last_run;
    void (*task_func)(void*);
    void* task_arg;
} Task;

void task1(void* arg) {
    printf("Task 1 ran at %ld\n", time(NULL));
}

void task2(void* arg) {
    printf("Task 2 ran at %ld\n", time(NULL));
}

void task3(void* arg) {
    printf("Task 3 ran at %ld\n", time(NULL));
}

void run_scheduler(Task tasks[], int num_tasks) {
    while (1) {
        for (int i = 0; i < num_tasks; i++) {
            if (time(NULL) - tasks[i].last_run >= tasks[i].interval) {
                tasks[i].last_run = time(NULL);
                tasks[i].task_func(tasks[i].task_arg);
            }
        }
    }
}

int main() {
    Task tasks[] = {
        {1, 5, 0, task1, NULL},
        {2, 10, 0, task2, NULL},
        {3, 30, 0, task3, NULL}
    };

    run_scheduler(tasks, 3);

    return EXIT_SUCCESS;
}