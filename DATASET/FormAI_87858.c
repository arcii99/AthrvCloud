//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scalable
#include <stdio.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    int priority;
    void (*func)();
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(int id, int priority, void (*func)()) {
    if (num_tasks >= MAX_TASKS) {
        printf("Max number of tasks reached\n");
        return;
    }
    tasks[num_tasks].id = id;
    tasks[num_tasks].priority = priority;
    tasks[num_tasks].func = func;
    num_tasks++;
}

void run_tasks() {
    Task *highest_priority_task;
    int i, j;
    while (num_tasks > 0) {
        // Find the highest priority task
        highest_priority_task = &tasks[0];
        for (i = 1; i < num_tasks; i++) {
            if (tasks[i].priority > highest_priority_task->priority) {
                highest_priority_task = &tasks[i];
            }
        }

        // Run the highest priority task
        printf("Running task %d\n", highest_priority_task->id);
        highest_priority_task->func();

        // Remove the task from the list
        for (j = 0; j < num_tasks-1; j++) {
            tasks[j] = tasks[j+1];
        }
        num_tasks--;
    }
}

void task1() {
    printf("Task 1 running\n");
}

void task2() {
    printf("Task 2 running\n");
}

void task3() {
    printf("Task 3 running\n");
}

int main() {
    add_task(1, 2, task1);
    add_task(2, 1, task2);
    add_task(3, 3, task3);
    run_tasks();
    return 0;
}