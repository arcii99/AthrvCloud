//FormAI DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>

// define the maximum number of tasks that can be scheduled
#define MAX_TASKS 10

/**
 * Represents a single task that needs to be scheduled.
 */
typedef struct {
    int task_id;
    char task_name[50];
    int priority;
    int time_to_execute;
} task_t;

/**
 * Represents the task scheduler that manages all the scheduled tasks.
 */
typedef struct {
    task_t tasks[MAX_TASKS];
    int num_tasks;
} task_scheduler_t;

/**
 * Adds a new task to the scheduler.
 */
void add_task(task_scheduler_t* scheduler, int id, const char* name, int priority, int time_to_execute) {
    // ensure there is room for the new task
    if (scheduler->num_tasks >= MAX_TASKS) {
        printf("Scheduler is full. Cannot add new task.\n");
        return;
    }

    // create the new task
    task_t new_task = { id, "", priority, time_to_execute };
    snprintf(new_task.task_name, 50, "%s", name); // copy the name to the task

    // add the new task to the scheduler
    scheduler->tasks[scheduler->num_tasks++] = new_task;
}

/**
 * Removes a task from the scheduler.
 */
void remove_task(task_scheduler_t* scheduler, int task_id) {
    int i;
    for (i = 0; i < scheduler->num_tasks; i++) {
        if (scheduler->tasks[i].task_id == task_id) {
            // found the task to remove
            break;
        }
    }

    if (i == scheduler->num_tasks) {
        // task with specified ID not found
        printf("Task with ID %d not found in scheduler.\n", task_id);
        return;
    }

    // shift all tasks after the removed task down
    for (; i < scheduler->num_tasks - 1; i++) {
        scheduler->tasks[i] = scheduler->tasks[i + 1];
    }

    // decrement the number of tasks in the scheduler
    scheduler->num_tasks--;
}

/**
 * Executes the next highest priority task in the scheduler.
 */
void execute_next_task(task_scheduler_t* scheduler) {
    // find the highest priority task
    int i, highest_priority = -1, highest_priority_index = -1;
    for (i = 0; i < scheduler->num_tasks; i++) {
        if (scheduler->tasks[i].priority > highest_priority) {
            highest_priority = scheduler->tasks[i].priority;
            highest_priority_index = i;
        }
    }

    if (highest_priority_index == -1) {
        // no tasks to execute
        printf("The task scheduler is empty.\n");
        return;
    }

    // execute the highest priority task
    task_t task_to_execute = scheduler->tasks[highest_priority_index];
    printf("Executing task %s (ID: %d)...\n", task_to_execute.task_name, task_to_execute.task_id);

    // wait for the task to complete
    int time_remaining = task_to_execute.time_to_execute;
    while (time_remaining > 0) {
        printf("Task %s (ID: %d) - Time remaining: %d seconds\n", task_to_execute.task_name, task_to_execute.task_id, time_remaining--);
    }

    // remove the executed task from the scheduler
    remove_task(scheduler, task_to_execute.task_id);
}

// demonstrate the task scheduler in action
int main() {
    // initialize the task scheduler
    task_scheduler_t scheduler = { .num_tasks = 0 };

    // add some tasks
    add_task(&scheduler, 1, "Send email", 2, 3);
    add_task(&scheduler, 2, "Write report", 1, 5);
    add_task(&scheduler, 3, "Make phone call", 3, 1);

    // execute tasks until scheduler is empty
    while (scheduler.num_tasks > 0) {
        execute_next_task(&scheduler);
    }

    return 0;
}