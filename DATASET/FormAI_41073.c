//FormAI DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME 20

typedef struct task {
    char name[MAX_TASK_NAME];
    int interval;
} task;

task tasks[MAX_TASKS];
int num_tasks = 0;

void init_tasks() {
    num_tasks = 0;
    // Define some example tasks with random intervals
    for (int i = 0; i < MAX_TASKS; i++) {
        int interval = (rand() % 5) + 1;
        snprintf(tasks[i].name, MAX_TASK_NAME, "Task %d", i+1);
        tasks[i].interval = interval;
        num_tasks++;
    }
}

void run_task(task t) {
    printf("Running task '%s'...\n", t.name);
}

void schedule_tasks() {
    time_t curr_time, prev_time;
    prev_time = time(NULL);
    while (1) {
        curr_time = time(NULL);
        // Check if any tasks are due to run
        for (int i = 0; i < num_tasks; i++) {
            if ((int)difftime(curr_time, prev_time) >= tasks[i].interval) {
                run_task(tasks[i]);
            }
        }
        prev_time = curr_time;
        // Sleep for one second
        sleep(1);
    }
}

int main() {
    // Initialize tasks
    init_tasks();

    // Schedule tasks
    schedule_tasks();

    return 0;
}