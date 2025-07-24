//FormAI DATASET v1.0 Category: Task Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define TASKS_MAX 5
#define INTERVAL 5

typedef struct task_s {
    int interval_sec;
    int count;
    void (*action)(void);
} task_t;

task_t tasks[TASKS_MAX];
int num_tasks = 0;

void add_task(int interval_sec, void (*action)(void)) {
    if (num_tasks >= TASKS_MAX) {
        printf("Max number of tasks reached! Cannot add any more tasks.\n");
        return;
    }
    task_t new_task = {interval_sec, 0, action};
    tasks[num_tasks++] = new_task;
}

bool should_run_task(task_t task) {
    return (task.interval_sec * task.count == 0) ? true : false;
}

void run_tasks() {
    int i;
    while (true) {
        for (i = 0; i < num_tasks; i++) {
            if (should_run_task(tasks[i])) {
                tasks[i].action();
                tasks[i].count++;
            }
            if (tasks[i].count * tasks[i].interval_sec >= 60) {
                tasks[i].count = 0;
            }
        }
        sleep(INTERVAL);
    }
}

void task1() {
    printf("Task 1 running every 10 seconds.\n");
}

void task2() {
    printf("Task 2 running every 5 seconds.\n");
}

int main() {
    add_task(10, task1);
    add_task(5, task2);
    run_tasks();
    return 0;
}