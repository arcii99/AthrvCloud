//FormAI DATASET v1.0 Category: Task Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Define the task structure
typedef struct Task {
    int id;
    int interval;
    int time_left;
    void (*function_pointer)(void);
} Task;

// Define the list of tasks
Task tasks[10];

// Define the function to add a new task
void add_task(int task_id, int task_interval, void (*task_function)(void)) {
    int i;
    // Find an empty slot in the task array
    for (i = 0; i < 10; i++) {
        if (tasks[i].id == 0) {
            // Assign task ID, interval and function pointer
            tasks[i].id = task_id;
            tasks[i].interval = task_interval;
            tasks[i].function_pointer = task_function;
            tasks[i].time_left = task_interval;
            break;
        }
    }
}

// Define the function to remove a task
void remove_task(int task_id) {
    int i;
    // Find the task with the given ID
    for (i = 0; i < 10; i++) {
        if (tasks[i].id == task_id) {
            // Set the task ID to 0 to mark it as empty/null
            tasks[i].id = 0;
            tasks[i].interval = 0;
            tasks[i].function_pointer = NULL;
            tasks[i].time_left = 0;
            break;
        }
    }
}

// Define the function to execute the scheduled tasks
void execute_tasks(void) {
    int i;
    // Loop through all the tasks
    for (i = 0; i < 10; i++) {
        // If the task is not empty/null
        if (tasks[i].id != 0) {
            // Decrement the time left for the task
            tasks[i].time_left--;
            // If the time left is zero or less
            if (tasks[i].time_left <= 0) {
                // Reset the time left to the interval
                tasks[i].time_left = tasks[i].interval;
                // Call the task's function
                tasks[i].function_pointer();
            }
        }
    }
}

// Define a sample task function
void print_hello(void) {
    printf("Hello\n");
}

int main(void) {
    int i;
    // Initialize all the tasks as empty/null
    for (i = 0; i < 10; i++) {
        tasks[i].id = 0;
        tasks[i].interval = 0;
        tasks[i].function_pointer = NULL;
        tasks[i].time_left = 0;
    }
    // Add a new task to print "Hello" every 2 seconds
    add_task(1, 2, print_hello);
    // Loop forever
    while (1) {
        // Execute the scheduled tasks
        execute_tasks();
    }
    // Should never get here
    return 0;
}