//FormAI DATASET v1.0 Category: Task Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the task structure
typedef struct {
    int task_id;
    int task_period;
    int next_run_time;
} task_t;

// Global variables
task_t tasks[5]; // An array of tasks to schedule
int num_tasks = 0; // The number of tasks in the array
int total_time = 100; // The total time to run the scheduler for
int current_time = 0; // The current time of the scheduler

// Function to add a task to the array
void add_task(int id, int period) {
    tasks[num_tasks].task_id = id; // Set the task id
    tasks[num_tasks].task_period = period; // Set the task period
    tasks[num_tasks].next_run_time = period; // Set the next run time to the period
    num_tasks++; // Increment the number of tasks
}

// Function to execute a task
void execute_task(int id) {
    printf("Executing task %d at time %d\n", id, current_time);
}

// Function to update the next run time of a task
void update_task(int id) {
    tasks[id].next_run_time += tasks[id].task_period;
}

// Function to run the scheduler
void run_scheduler() {
    for (current_time = 0; current_time < total_time; current_time++) {
        // Check each task
        for (int i = 0; i < num_tasks; i++) {
            // If the current time matches the next run time
            if (current_time == tasks[i].next_run_time) {
                execute_task(tasks[i].task_id); // Execute the task
                update_task(i); // Update the next run time
            }
        }
    }
}

int main() {
    // Add some tasks to the array
    add_task(1, 10);
    add_task(2, 5);
    add_task(3, 20);

    // Run the scheduler
    run_scheduler();

    return 0;
}