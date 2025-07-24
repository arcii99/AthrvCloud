//FormAI DATASET v1.0 Category: Task Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_TASKS 10
#define TASK_INTERVAL 1000 // 1 second

typedef void (*task_func_t)(void);

typedef struct {
    task_func_t func;
    time_t last_time;
    bool enabled;
} task_t;

static task_t tasks[NUM_TASKS];

void task1(void) {
    printf("Task 1 running...\n");
}

void task2(void) {
    printf("Task 2 running...\n");
}

void task3(void) {
    printf("Task 3 running...\n");
}

// Add more tasks as needed...

int main(void) {
    // Initialize task array
    tasks[0] = (task_t) { .func = task1 };
    tasks[1] = (task_t) { .func = task2 };
    tasks[2] = (task_t) { .func = task3 };
    for (int i = 3; i < NUM_TASKS; i++) {
        tasks[i] = (task_t) { .func = NULL };
    }

    // Initialize timer
    time_t current_time = time(NULL);
    time_t last_time = current_time;

    // Loop indefinitely
    while (true) {
        // Get current time
        current_time = time(NULL);

        // Check if it's time to run each task
        for (int i = 0; i < NUM_TASKS; i++) {
            if (tasks[i].func != NULL && tasks[i].enabled && current_time - tasks[i].last_time >= TASK_INTERVAL) {
                tasks[i].func();
                tasks[i].last_time = current_time;
            }
        }

        // Sleep for a short while to avoid high CPU usage
        usleep(1000);
    }

    return EXIT_SUCCESS;
}