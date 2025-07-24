//FormAI DATASET v1.0 Category: Task Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_WAIT 30

int tasks[MAX_TASKS];
int durations[MAX_TASKS];
int current_time = 0;

void add_task(int task_id, int duration) {
    if (task_id < MAX_TASKS) {
        tasks[task_id] = 1;
        durations[task_id] = duration;
    }
}

void run_task(int task_id) {
    printf("Running task %d\n", task_id);
    int wait_time = rand() % MAX_WAIT;
    current_time += durations[task_id] + wait_time;
    printf("Task %d finished in %d seconds\n", task_id, durations[task_id] + wait_time);
    tasks[task_id] = 0;
}

int main() {
    srand(time(NULL));
    printf("Welcome to the unique C Task Scheduler!\n\n");
    
    // Add some tasks
    add_task(1, 2);
    add_task(3, 4);
    add_task(7, 3);
    
    while (1) {
        printf("Current time: %d\n", current_time);
        // Check for completed tasks
        for (int i = 0; i < MAX_TASKS; i++) {
            if (tasks[i] && current_time >= durations[i]) {
                run_task(i);
            }
        }
        // Check for available tasks
        int available_tasks = 0;
        for (int i = 0; i < MAX_TASKS; i++) {
            if (tasks[i]) {
                available_tasks++;
            }
        }
        if (available_tasks == 0) {
            printf("No tasks remaining.\n");
            break;
        }
        // Wait for a second
        sleep(1);
        current_time++;
    }
    printf("\nAll tasks completed.\n");
    return 0;
}