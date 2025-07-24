//FormAI DATASET v1.0 Category: Task Scheduler ; Style: protected
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LENGTH 20

typedef struct {
    char name[MAX_TASK_NAME_LENGTH];
    int priority;
    int time_remaining;
} Task;

int main(void) {

    Task task_list[MAX_TASKS];
    int num_tasks = 0;

    // Add tasks to the task list
    strcpy(task_list[num_tasks].name, "Task One");
    task_list[num_tasks].priority = 2;
    task_list[num_tasks].time_remaining = 5;
    num_tasks++;

    strcpy(task_list[num_tasks].name, "Task Two");
    task_list[num_tasks].priority = 3;
    task_list[num_tasks].time_remaining = 8;
    num_tasks++;

    strcpy(task_list[num_tasks].name, "Task Three");
    task_list[num_tasks].priority = 1;
    task_list[num_tasks].time_remaining = 3;
    num_tasks++;

    // Run the scheduler
    int clock = 0; // Simulate a system clock
    while (num_tasks > 0) {
        int highest_priority = 0; // The highest priority found so far
        int selected_task = -1; // The index of the selected task

        // Find the task with the highest priority
        for (int i=0; i<num_tasks; i++) {
            if (task_list[i].priority > highest_priority) {
                highest_priority = task_list[i].priority;
                selected_task = i;
            }
        }

        // Decrement the time remaining for the selected task
        task_list[selected_task].time_remaining--;

        // Check if the task is completed
        if (task_list[selected_task].time_remaining == 0) {
            printf("Task %s completed at clock time %d\n", task_list[selected_task].name, clock);
            num_tasks--;
            // Remove the completed task from the list by swapping it with the last task
            if (selected_task != num_tasks) {
                task_list[selected_task] = task_list[num_tasks];
            }
        }

        clock++;
    }

    printf("All tasks completed.\n");

    return 0;
}