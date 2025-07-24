//FormAI DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 5

typedef enum {false, true} bool;

typedef struct Task {
    int id;
    int priority;
    int time_to_execute;
    bool executed;
} Task;

void execute_task(Task *task) {
    printf("Executing Task %d with priority %d for %d seconds\n", task->id, task->priority, task->time_to_execute);
    task->executed = true;
}

int main() {
    srand(time(NULL));
    Task tasks[MAX_TASKS];
    int num_tasks = rand() % MAX_TASKS + 1;

    // Generate random tasks
    for (int i = 0; i < num_tasks; i++) {
        tasks[i].id = i+1;
        tasks[i].priority = rand() % MAX_PRIORITY + 1;
        tasks[i].time_to_execute = rand() % 10 + 1; // task can take anywhere from 1-10 seconds to execute
        tasks[i].executed = false;
    }

    printf("Generated %d tasks:\n", num_tasks);
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d: Priority %d, Execution Time %d seconds\n", tasks[i].id, tasks[i].priority, tasks[i].time_to_execute);
    }

    // Execute tasks in order of priority until all tasks have been executed
    while (true) {
        Task *highest_priority_task = NULL;
        for (int i = 0; i < num_tasks; i++) {
            if (!tasks[i].executed && (highest_priority_task == NULL || tasks[i].priority > highest_priority_task->priority)) {
                highest_priority_task = &tasks[i];
            }
        }
        if (highest_priority_task != NULL) {
            execute_task(highest_priority_task);
        } else {
            break;
        }
    }

    printf("All tasks have been executed\n");

    return 0;
}