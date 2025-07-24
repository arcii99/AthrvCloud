//FormAI DATASET v1.0 Category: Task Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10 // Maximum number of tasks

// Define a struct for the task
typedef struct {
    int interval; // Interval in seconds
    int counter; // Counter to keep track of how many times the task has been executed
    void (*task_function)(void); // Pointer to the function to execute the task
} task_t;

// Define a struct for the task scheduler
typedef struct {
    task_t tasks[MAX_TASKS]; // Array of tasks
    int num_tasks; // Number of tasks in the array
} task_scheduler_t;

// Initialize the task scheduler
void task_scheduler_init(task_scheduler_t* scheduler) {
    scheduler->num_tasks = 0;
}

// Add a new task to the scheduler
int task_scheduler_add_task(task_scheduler_t* scheduler, int interval, void (*task_function)(void)) {
    if (scheduler->num_tasks < MAX_TASKS) {
        task_t new_task = {interval, interval, task_function};
        scheduler->tasks[scheduler->num_tasks] = new_task;
        scheduler->num_tasks++;
        return 1;
    }
    return 0;
}

// Run the task scheduler
void task_scheduler_run(task_scheduler_t* scheduler) {
    while (1) {
        for (int i = 0; i < scheduler->num_tasks; i++) {
            if (scheduler->tasks[i].counter == 0) {
                scheduler->tasks[i].task_function(); // Execute the task
                scheduler->tasks[i].counter = scheduler->tasks[i].interval; // Reset the counter
            }
            scheduler->tasks[i].counter--;
        }
    }
}

// Example task functions
void task1(void) {
    printf("Task 1 executed\n");
}

void task2(void) {
    printf("Task 2 executed\n");
}

int main(void) {
    task_scheduler_t scheduler;
    task_scheduler_init(&scheduler);
    task_scheduler_add_task(&scheduler, 2, &task1);
    task_scheduler_add_task(&scheduler, 5, &task2);
    task_scheduler_run(&scheduler);
    return 0;
}