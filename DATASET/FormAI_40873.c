//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Ada Lovelace
// This code demonstrates a simple task scheduler that can run multiple tasks
// in a round-robin manner.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TASKS 3
#define TIME_QUANTUM 5

typedef struct task {
    int id;
    int remaining_time;
} Task;

// Returns a random integer between min and max (inclusive).
int random_int(int min, int max) {
    static int initialized = 0;

    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }

    return (rand() % (max - min + 1)) + min;
}

// Initializes a task with the given ID and a random remaining time between
// 1 and 10.
void init_task(Task *t, int id) {
    t->id = id;
    t->remaining_time = random_int(1, 10);
}

// Prints the given task to stdout.
void print_task(Task *t) {
    printf("Task %d (remaining time: %d)\n", t->id, t->remaining_time);
}

int main() {
    Task tasks[NUM_TASKS];
    int current_task = 0;

    // Initialize the tasks.
    for (int i = 0; i < NUM_TASKS; i++) {
        init_task(&tasks[i], i + 1);
        print_task(&tasks[i]);
    }

    // Schedule the tasks.
    while (1) {
        Task *current = &tasks[current_task];

        if (current->remaining_time > 0) {
            // Execute the task for the time quantum.
            printf("Executing ");
            print_task(current);
            current->remaining_time -= TIME_QUANTUM;

            // Check if the task has finished.
            if (current->remaining_time <= 0) {
                printf("Task %d finished.\n", current->id);
            } else {
                printf("Task %d paused.\n", current->id);
            }
        }

        // Move on to the next task.
        current_task = (current_task + 1) % NUM_TASKS;

        // Check if all tasks have finished.
        if (tasks[0].remaining_time <= 0 && tasks[1].remaining_time <= 0 && tasks[2].remaining_time <= 0) {
            break;
        }
    }

    return 0;
}