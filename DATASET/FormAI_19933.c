//FormAI DATASET v1.0 Category: Task Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum number of tasks
#define MAX_TASKS 100

// Define structure for a task
struct Task {
    char name[50];
    int priority; // 1 (highest) to 10 (lowest)
    int interval; // execution interval in seconds
    time_t last_executed_time;
};

// Declare global variables
struct Task tasks[MAX_TASKS];
int num_tasks = 0;

// Function to add a task to the task scheduler
void add_task(const char *name, int priority, int interval) {
    if (num_tasks < MAX_TASKS) {
        struct Task new_task;
        strcpy(new_task.name, name);
        new_task.priority = priority;
        new_task.interval = interval;
        new_task.last_executed_time = time(NULL);
        tasks[num_tasks++] = new_task;
        printf("Added task %s with priority %d and interval %d seconds.\n", name, priority, interval);
    } else {
        printf("Error: Maximum number of tasks reached.\n");
    }
}

// Function to remove a task from the task scheduler
void remove_task(const char *name) {
    for (int i = 0; i < num_tasks; i++) {
        if (strcmp(tasks[i].name, name) == 0) {
            for (int j = i; j < num_tasks - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            num_tasks--;
            printf("Removed task %s.\n", name);
            return;
        }
    }
    printf("Error: Task %s not found.\n", name);
}

// Function to execute a task
void execute_task(struct Task t) {
    printf("Executing task %s with priority %d.\n", t.name, t.priority);
    // Add code here to actually execute the task
    t.last_executed_time = time(NULL);
}

// Function to check if a task needs to be executed
int needs_executing(struct Task t) {
    if (difftime(time(NULL), t.last_executed_time) >= t.interval) {
        return 1;
    } else {
        return 0;
    }
}

// Function to sort tasks by priority (highest first)
void sort_tasks() {
    for (int i = 0; i < num_tasks - 1; i++) {
        for (int j = i + 1; j < num_tasks; j++) {
            if (tasks[i].priority < tasks[j].priority) {
                struct Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

int main() {
    // Add some example tasks
    add_task("Task 1", 5, 5);
    add_task("Task 2", 8, 10);
    add_task("Task 3", 2, 2);
    add_task("Task 4", 10, 20);
    add_task("Task 5", 4, 4);
    
    // Main loop
    while (1) {
        // Sort tasks by priority
        sort_tasks();
        
        // Execute tasks that need to be executed
        for (int i = 0; i < num_tasks; i++) {
            if (needs_executing(tasks[i])) {
                execute_task(tasks[i]);
            }
        }
        
        // Wait for 1 second before checking again
        sleep(1);
    }
    
    return 0;
}