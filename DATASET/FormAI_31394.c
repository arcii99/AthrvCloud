//FormAI DATASET v1.0 Category: Task Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int priority;
    int duration;
} Task;

void print_task(Task task) {
    printf("Name: %s\n", task.name);
    printf("Priority: %d\n", task.priority);
    printf("Duration: %d\n\n", task.duration);
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize tasks
    Task tasks[MAX_TASKS];

    for (int i = 0; i < MAX_TASKS; i++) {
        // Generate task name
        char name[MAX_NAME_LENGTH];
        sprintf(name, "Task %d", i+1);

        // Generate task priority (1-10)
        int priority = rand() % 10 + 1;

        // Generate task duration (1-5 seconds)
        int duration = rand() % 5 + 1;

        // Add task to array
        Task task = {name, priority, duration};
        tasks[i] = task;
    }

    // Print unsorted tasks
    printf("Unsorted Tasks:\n\n");

    for (int i = 0; i < MAX_TASKS; i++) {
        print_task(tasks[i]);
    }

    // Sort tasks by priority (bubble sort)
    for (int i = 0; i < MAX_TASKS - 1; i++) {
        for (int j = 0; j < MAX_TASKS - i - 1; j++) {
            if (tasks[j].priority < tasks[j+1].priority) {
                // Swap tasks
                Task temp = tasks[j];
                tasks[j] = tasks[j+1];
                tasks[j+1] = temp;
            }
        }
    }

    // Print sorted tasks
    printf("Sorted Tasks:\n\n");

    for (int i = 0; i < MAX_TASKS; i++) {
        print_task(tasks[i]);
    }

    // Schedule tasks (in priority order)
    printf("Scheduling Tasks:\n\n");

    for (int i = 0; i < MAX_TASKS; i++) {
        printf("Running Task %d...\n", i+1);
        sleep(tasks[i].duration);
        printf("Finished Task %d!\n\n", i+1);
    }

    return 0;
}