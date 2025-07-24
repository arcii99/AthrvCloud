//FormAI DATASET v1.0 Category: Task Scheduler ; Style: futuristic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NUM_TASKS 10

typedef struct {
    int id;
    int priority;
    int execution_time;
} Task;

int main() {
    Task tasks[NUM_TASKS];
    int i, j, current_time = 0, total_time = 0;
    srand(time(NULL)); // initialize random seed

    // Generate tasks randomly
    for (i = 0; i < NUM_TASKS; i++) {
        tasks[i].id = i;
        tasks[i].priority = rand() % 10 + 1; // priority between 1 and 10
        tasks[i].execution_time = rand() % 20 + 1; // execution time between 1 and 20
        total_time += tasks[i].execution_time;
    }

    // Sort tasks by priority (higher priority first)
    for (i = 0; i < NUM_TASKS - 1; i++) {
        for (j = i + 1; j < NUM_TASKS; j++) {
            if (tasks[i].priority < tasks[j].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    printf("Task Scheduler starting...\n");

    // Execute tasks in order of priority
    for (i = 0; i < NUM_TASKS; i++) {
        printf("Executing task %d for %d seconds\n", tasks[i].id, tasks[i].execution_time);
        current_time += tasks[i].execution_time;
        printf("Current time: %d\n", current_time);
    }

    printf("Task Scheduler complete! Total execution time: %d\n", total_time);

    return 0;
}