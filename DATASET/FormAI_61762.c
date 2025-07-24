//FormAI DATASET v1.0 Category: Task Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of tasks that can be scheduled
#define MAX_TASKS 10

// Define the maximum duration of a task in seconds
#define MAX_DURATION 5

// Define the number of seconds in a minute
#define SECONDS_IN_MINUTE 60 

// Define a structure for a task
typedef struct {
    int id; // ID of the task
    int duration; // Duration of the task in seconds
    int priority; // Priority of the task (higher number = higher priority)
    int scheduled_time; // Time at which the task is scheduled to run
} Task;

// Define a structure for the task scheduler
typedef struct {
    Task tasks[MAX_TASKS]; // Array of tasks
    int num_tasks; // Number of tasks currently in the scheduler
    int current_time; // Current time in seconds since the start of the program
} TaskScheduler;

// Function to add a new task to the scheduler
void add_task(TaskScheduler* scheduler, int duration, int priority)
{
    // Check if there is space for a new task
    if (scheduler->num_tasks >= MAX_TASKS) {
        printf("Error: maximum number of tasks reached\n");
        return;
    }
    
    // Set the ID of the new task
    int id = scheduler->num_tasks + 1;
    
    // Set the scheduled time of the new task
    int scheduled_time = scheduler->current_time + (rand() % SECONDS_IN_MINUTE); // Schedule the task to run within the next minute
    
    // Set the properties of the new task
    Task new_task = {id, duration, priority, scheduled_time};
    
    // Add the new task to the scheduler
    scheduler->tasks[scheduler->num_tasks++] = new_task;
    
    printf("Task added: ID %d, duration %d seconds, priority %d, scheduled to run at %02d:%02d\n", id, duration, priority, scheduled_time / SECONDS_IN_MINUTE, scheduled_time % SECONDS_IN_MINUTE);
}

// Function to remove a task from the scheduler
void remove_task(TaskScheduler* scheduler, int id)
{
    int index = -1;
    
    // Find the task with the given ID
    for (int i = 0; i < scheduler->num_tasks; i++) {
        if (scheduler->tasks[i].id == id) {
            index = i;
            break;
        }
    }
    
    // Remove the task if it was found
    if (index >= 0) {
        printf("Task removed: ID %d\n", id);
        for (int i = index; i < scheduler->num_tasks - 1; i++) {
            scheduler->tasks[i] = scheduler->tasks[i + 1];
        }
        scheduler->num_tasks--;
    }
    else {
        printf("Error: task with ID %d not found\n", id);
    }
}

// Function to run the scheduler
void run_scheduler(TaskScheduler* scheduler)
{
    printf("Starting task scheduler...\n");
    
    // Loop until all tasks have been completed
    while (scheduler->num_tasks > 0) {
        // Find the highest priority task that is scheduled to run at or before the current time
        int next_task_index = -1;
        int highest_priority = -1;
        for (int i = 0; i < scheduler->num_tasks; i++) {
            if (scheduler->tasks[i].scheduled_time <= scheduler->current_time && scheduler->tasks[i].priority > highest_priority) {
                next_task_index = i;
                highest_priority = scheduler->tasks[i].priority;
            }
        }
        
        // Run the next task
        if (next_task_index >= 0) {
            Task* next_task = &scheduler->tasks[next_task_index];
            printf("Running task: ID %d, duration %d seconds\n", next_task->id, next_task->duration);
            scheduler->current_time += next_task->duration;
            remove_task(scheduler, next_task->id);
        }
        else {
            // No tasks are scheduled to run at or before the current time
            printf("Idle...\n");
            scheduler->current_time++;
        }
    }
    
    printf("All tasks completed!\n");
}

int main()
{
    srand(time(NULL)); // Initialize the random number generator
    
    TaskScheduler scheduler = {0};
    
    // Add some example tasks to the scheduler
    add_task(&scheduler, 3, 2);
    add_task(&scheduler, 2, 1);
    add_task(&scheduler, 5, 3);
    add_task(&scheduler, 4, 2);
    add_task(&scheduler, 1, 1);
    
    run_scheduler(&scheduler);
    
    return 0;
}