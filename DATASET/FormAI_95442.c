//FormAI DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TASKS 5 // Number of tasks
#define MAX_DURATION 5 // Maximum duration of a task
#define QUANTUM 3 // Time quantum allotted to each task

// Function to execute a task
void execute_task(int task_id, int duration) {
    printf("Executing task %d for %d seconds...\n", task_id, duration);
    sleep(duration);
    printf("Task %d completed.\n", task_id);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Initialize array of task durations
    int task_durations[TASKS];
    for (int i = 0; i < TASKS; i++) {
        task_durations[i] = rand() % MAX_DURATION + 1; // Choose a random duration between 1 and MAX_DURATION seconds
    }

    // Display the durations of each task
    printf("Task Durations:\n");
    for (int i = 0; i < TASKS; i++) {
        printf("Task %d: %d seconds\n", i+1, task_durations[i]);
    }

    // Execute tasks in a scheduled manner
    int current_task = 0;
    while (current_task < TASKS) {
        printf("Time slice %d - %d seconds:\n", current_task*QUANTUM+1, (current_task+1)*QUANTUM);

        int time_left = QUANTUM;
        while (time_left > 0 && current_task < TASKS) {
            int duration = task_durations[current_task];
            if (duration > time_left) {
                duration = time_left; // Adjust duration to fit within time slice
            }
            execute_task(current_task+1, duration);
            time_left -= duration;
            task_durations[current_task] -= duration;
            if (task_durations[current_task] == 0) {
                current_task++; // Move on to the next task when the current task has completed
            }
        }
        printf("\n");
    }

    printf("All tasks complete.\n");

    return 0;
}