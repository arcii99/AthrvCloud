//FormAI DATASET v1.0 Category: Task Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define maximum number of tasks that can be scheduled
#define MAX_TASKS 10

// Define task structure
typedef struct Task {
    void (*func)(void);
    int delay;
    int count;
} Task;

// Define global task array
Task tasks[MAX_TASKS];

// Define current number of tasks scheduled
int num_tasks = 0;

// Function to add a task to the task scheduler
void add_task(void (*func)(void), int delay, int count) {
    // Check if there is room for any more tasks
    if (num_tasks == MAX_TASKS) {
        printf("Cannot schedule any more tasks.\n");
        return;
    }

    // Add the new task to the task array
    tasks[num_tasks].func = func;
    tasks[num_tasks].delay = delay;
    tasks[num_tasks].count = count;
    num_tasks++;
}

// Function to remove a task from the task scheduler
void remove_task(int index) {
    // Shift all remaining tasks down by one index
    for (int i = index; i < num_tasks-1; i++) {
        tasks[i] = tasks[i+1];
    }

    // Reset the last task in the array and decrement num_tasks
    tasks[num_tasks-1].func = NULL;
    tasks[num_tasks-1].delay = 0;
    tasks[num_tasks-1].count = 0;
    num_tasks--;
}

// Function to run the task scheduler
void run_tasks() {
    // Initialize an array to keep track of task delays
    int delays[MAX_TASKS];
    for (int i = 0; i < num_tasks; i++) {
        delays[i] = tasks[i].delay;
    }

    // Main task scheduler loop
    int i = 0;
    int count = 0;
    while (num_tasks > 0) {
        // Run current task and decrement delay
        if (delays[i] <= 0) {
            tasks[i].func();
            delays[i] = tasks[i].delay;
            tasks[i].count--;

            // Remove task if count has reached 0
            if (tasks[i].count == 0) {
                remove_task(i);
                i--;
            }
        }
        delays[i]--;

        // Move to next task and wrap around if end of task array is reached
        i++;
        if (i >= num_tasks) {
            i = 0;
            count++;
        }
    }
}

// Dummy task function
void task1() {
    printf("Executing Task 1\n");
}

// Another dummy task function
void task2() {
    printf("Executing Task 2\n");
}

int main() {
    // Add tasks to the task scheduler
    add_task(&task1, 2, 5);
    add_task(&task2, 3, 3);

    // Run the task scheduler
    run_tasks();

    return 0;
}