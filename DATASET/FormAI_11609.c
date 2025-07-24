//FormAI DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define TASK_COUNT 5

/* Task structure */
typedef struct {
    int id;
    int interval;
    int remaining;
    void (*function)(int);
} Task;

/* Task functions */
void task1(int id) { printf("Task %d: Hello, world!\n", id); }
void task2(int id) { printf("Task %d: This is a test.\n", id); }
void task3(int id) { printf("Task %d: Goodbye, world!\n", id); }
void task4(int id) { printf("Task %d: Another test.\n", id); }
void task5(int id) { printf("Task %d: Done.\n", id); }

/* Task list */
Task taskList[TASK_COUNT] = {
    {1, 3, 3, task1},
    {2, 5, 5, task2},
    {3, 2, 2, task3},
    {4, 4, 4, task4},
    {5, 1, 1, task5},
};

/* Main program */
int main() {
    int i, j;

    /* Run tasks until all remaining intervals are zero */
    for (;;) {
        /* Check if all tasks are completed */
        int complete = 1;
        for (i = 0; i < TASK_COUNT; i++) {
            if (taskList[i].remaining > 0) {
                complete = 0;
                break;
            }
        }
        if (complete) {
            break;
        }

        /* Run tasks with remaining intervals */
        for (i = 0; i < TASK_COUNT; i++) {
            if (taskList[i].remaining > 0) {
                /* Run the task and reduce the remaining interval */
                taskList[i].function(taskList[i].id);
                taskList[i].remaining--;

                /* Reset the interval if it reaches zero */
                if (taskList[i].remaining == 0) {
                    taskList[i].remaining = taskList[i].interval;
                }
            }
        }
    }

    return 0;
}