//FormAI DATASET v1.0 Category: Task Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a task
typedef struct {
    int id;
    int priority;
    int time;
    int remainingTime;
} Task;

// Define a function to initialize a task with random values
void initializeTask(Task* task, int id) {
    task->id = id;
    task->priority = rand() % 10 + 1; // priority between 1 and 10
    task->time = rand() % 10 + 1; // execution time between 1 and 10 seconds
    task->remainingTime = task->time;
}

// Define a function to print a task
void printTask(Task* task) {
    printf("Task %d (priority %d, execution time %d seconds, %d seconds remaining)\n", task->id, task->priority, task->time, task->remainingTime);
}

// Define a function to swap two tasks
void swap(Task* a, Task* b) {
    Task t = *a;
    *a = *b;
    *b = t;
}

// Define a function to sort an array of tasks by priority
void sortByPriority(Task* tasks, int numTasks) {
    for (int i = 0; i < numTasks; i++) {
        for (int j = i + 1; j < numTasks; j++) {
            if (tasks[i].priority < tasks[j].priority) {
                swap(&tasks[i], &tasks[j]);
            }
        }
    }
}

// Define a function to simulate executing a task
void executeTask(Task* task) {
    printf("Executing task %d\n", task->id);
    task->remainingTime = 0;
}

int main() {
    const int NUM_TASKS = 5;
    const int MAX_SECONDS = 20;
    Task tasks[NUM_TASKS];

    // Initialize tasks with random values
    for (int i = 0; i < NUM_TASKS; i++) {
        initializeTask(&tasks[i], i);
        printTask(&tasks[i]);
    }

    printf("\n");

    // Sort tasks by priority
    sortByPriority(tasks, NUM_TASKS);

    int seconds = 0;
    while (seconds < MAX_SECONDS) {
        printf("Time elapsed: %d seconds\n", seconds);

        // Execute highest priority task
        if (tasks[0].remainingTime > 0) {
            executeTask(&tasks[0]);
        }

        // Decrement remaining time for all tasks
        for (int i = 0; i < NUM_TASKS; i++) {
            if (tasks[i].remainingTime > 0) {
                tasks[i].remainingTime--;
            }
        }

        // Sort tasks by priority
        sortByPriority(tasks, NUM_TASKS);

        // Wait for one second
        sleep(1);
        seconds++;
    }

    return 0;
}