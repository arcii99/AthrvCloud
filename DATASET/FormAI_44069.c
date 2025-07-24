//FormAI DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of tasks that can be scheduled
#define MAX_TASKS 10

// Define a structure to hold information about a task
typedef struct {
    int id;
    int priority;
    int time_remaining;
    bool is_completed;
} Task;

// Define a structure to hold information about the task scheduler
typedef struct {
    Task tasks[MAX_TASKS];
    int num_tasks;
} TaskScheduler;

// Initialize a task scheduler
void initialize_scheduler(TaskScheduler *scheduler) {
    for (int i = 0; i < MAX_TASKS; i++) {
        scheduler->tasks[i].id = 0;
        scheduler->tasks[i].priority = 0;
        scheduler->tasks[i].time_remaining = 0;
        scheduler->tasks[i].is_completed = false;
    }
    scheduler->num_tasks = 0;
}

// Add a task to the scheduler
void add_task(TaskScheduler *scheduler, int id, int priority, int time) {
    // Check that the scheduler has not reached its maximum capacity
    if (scheduler->num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached\n");
        return;
    }

    // Create the task and add it to the scheduler
    Task task;
    task.id = id;
    task.priority = priority;
    task.time_remaining = time;
    task.is_completed = false;
    scheduler->tasks[scheduler->num_tasks++] = task;
}

// Remove a task from the scheduler
void remove_task(TaskScheduler *scheduler, int id) {
    // Find the task with the specified ID
    int index = -1;
    for (int i = 0; i < scheduler->num_tasks; i++) {
        if (scheduler->tasks[i].id == id) {
            index = i;
            break;
        }
    }

    // If the task was not found, return an error
    if (index == -1) {
        printf("Error: Task not found\n");
        return;
    }

    // Remove the task by shifting all subsequent tasks one position to the left
    for (int i = index + 1; i < scheduler->num_tasks; i++) {
        scheduler->tasks[i-1] = scheduler->tasks[i];
    }
    scheduler->num_tasks--;
}

// Execute the highest-priority task in the scheduler
void execute_task(TaskScheduler *scheduler) {
    // Find the highest-priority task that has not already been completed
    int highest_priority = -1;
    int index = -1;
    for (int i = 0; i < scheduler->num_tasks; i++) {
        if (!scheduler->tasks[i].is_completed && scheduler->tasks[i].priority > highest_priority) {
            highest_priority = scheduler->tasks[i].priority;
            index = i;
        }
    }

    // If no uncompleted tasks were found, return
    if (index == -1) {
        return;
    }

    // Decrement the time remaining for the task and mark it as completed if necessary
    scheduler->tasks[index].time_remaining--;
    if (scheduler->tasks[index].time_remaining == 0) {
        scheduler->tasks[index].is_completed = true;
    }
}

int main() {
    // Initialize the task scheduler
    TaskScheduler scheduler;
    initialize_scheduler(&scheduler);

    // Add some tasks to the scheduler
    add_task(&scheduler, 1, 3, 5);
    add_task(&scheduler, 2, 2, 3);
    add_task(&scheduler, 3, 1, 8);

    // Execute tasks until all are completed
    while (scheduler.num_tasks > 0) {
        execute_task(&scheduler);
    }

    printf("All tasks completed\n");

    return 0;
}