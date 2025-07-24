//FormAI DATASET v1.0 Category: Task Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    int interval;
    int elapsed_time;
    void (*task)();
} Task;

Task task_list[MAX_TASKS];
int num_tasks = 0;

void add_task(int interval, void (*task)()) {
    if (num_tasks >= MAX_TASKS) {
        printf("Maximum number of tasks reached.\n");
        return;
    }
    Task new_task = {
        .id = num_tasks,
        .interval = interval,
        .elapsed_time = 0,
        .task = task
    };
    task_list[num_tasks++] = new_task;
}

void run_task(Task *task) {
    printf("Running task %d.\n", task->id);
    task->task();
}

void check_elapsed_time(Task *task) {
    if (task->elapsed_time >= task->interval) {
        run_task(task);
        task->elapsed_time = 0;
    } else {
        task->elapsed_time++;
    }
}

void run_tasks() {
    while (true) {
        for (int i = 0; i < num_tasks; i++) {
            check_elapsed_time(&task_list[i]);
        }
    }
}

void task1() {
    printf("Task 1 running.\n");
}

void task2() {
    printf("Task 2 running.\n");
}

int main() {
    add_task(2, &task1);
    add_task(5, &task2);
    run_tasks();
    return 0;
}