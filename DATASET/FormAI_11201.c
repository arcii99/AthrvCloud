//FormAI DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 10

/* Struct to hold information about a single task */
typedef struct {
    int interval; // Task interval in seconds
    int remaining; // Remaining time until the next execution
    void (*function)(void); // Pointer to function to be executed
} Task;

/* Array of scheduled tasks */
Task tasks[MAX_TASKS] = {{0}};

/* Signal handler for SIGALRM */
void sig_handler(int signo) {
    static int current_task = 0;
    int i;

    // Clear the signal
    signal(signo, sig_handler);

    // Loop through the tasks and execute the ones that are due
    for (i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].function != NULL) {
            tasks[i].remaining--;
            if (tasks[i].remaining <= 0) {
                // Execute the task
                tasks[i].function();
                // Reset the remaining time
                tasks[i].remaining = tasks[i].interval;
            }
        }
    }

    // Move to the next task
    current_task = (current_task + 1) % MAX_TASKS;

    // Schedule the next alarm
    alarm(tasks[current_task].remaining);
}

/* Function to add a new task to the schedule */
void add_task(int interval, void (*function)(void)) {
    int i;

    // Find the next free slot in the tasks array
    for (i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].function == NULL) {
            // Found a free slot
            tasks[i].interval = interval;
            tasks[i].remaining = interval;
            tasks[i].function = function;
            return;
        }
    }

    // If we get here, all slots are full
    printf("Failed to add task: max tasks reached.\n");
}

/* Example task functions */
void task_1(void) {
    printf("Task 1 executed.\n");
}

void task_2(void) {
    printf("Task 2 executed.\n");
}

void task_3(void) {
    printf("Task 3 executed.\n");
}

int main(void) {
    // Set the signal handler
    signal(SIGALRM, sig_handler);

    // Schedule some tasks
    add_task(2, task_1);
    add_task(5, task_2);
    add_task(10, task_3);

    // Schedule the first alarm
    alarm(tasks[0].remaining);

    // Keep the program running
    while (1) {
        sleep(1);
    }

    return 0;
}