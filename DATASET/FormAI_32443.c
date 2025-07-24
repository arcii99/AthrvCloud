//FormAI DATASET v1.0 Category: Task Scheduler ; Style: puzzling
// Welcome to the Task Scheduler program!
// Your task, should you choose to accept it, is to solve the puzzle and schedule the tasks accordingly.
// You have been given an array of tasks with their priorities and their execution times.
// Your job is to schedule the tasks in such a way that the total execution time is minimized and the priorities are maintained.

#include <stdio.h>
#include <stdlib.h>

// Task struct definition
typedef struct task {
    int priority; // Lower number indicates higher priority
    int execution_time;
} Task;

// Function to sort tasks by priority
int cmp_by_priority(const void* a, const void* b) {
    Task* task1 = (Task*)a;
    Task* task2 = (Task*)b;

    if (task1->priority < task2->priority) {
        return -1;
    } else if (task1->priority > task2->priority) {
        return 1;
    } else {
        return 0;
    }
}

// Function to sort tasks by execution time
int cmp_by_exec_time(const void* a, const void* b) {
    Task* task1 = (Task*)a;
    Task* task2 = (Task*)b;
    
    if (task1->execution_time < task2->execution_time) {
        return -1;
    } else if (task1->execution_time > task2->execution_time) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Initialize tasks array
    Task tasks[] = {
        {3, 10},
        {1, 13},
        {2, 15},
        {5, 7},
        {4, 9},
    };

    // Calculate number of tasks in the array
    int num_tasks = sizeof(tasks) / sizeof(tasks[0]);

    // Sort tasks by priority
    qsort(tasks, num_tasks, sizeof(Task), cmp_by_priority);

    // Initialize task order array
    int task_order[num_tasks];

    // Initialize task completion time array
    int task_comp_time[num_tasks];

    // Initialize total execution time of tasks
    int total_exec_time = 0;

    // Iterate through tasks and schedule them in order
    for (int i = 0; i < num_tasks; i++) {
        task_order[i] = i;

        // Calculate completion time of current task
        if (i == 0) {
            task_comp_time[i] = tasks[i].execution_time;
        } else {
            task_comp_time[i] = task_comp_time[i-1] + tasks[i].execution_time;
        }

        // Add current task's execution time to total exec time
        total_exec_time += tasks[i].execution_time;
    }

    // Sort task order array by execution time
    qsort(task_order, num_tasks, sizeof(int), cmp_by_exec_time);

    // Print solution
    printf("Task order: ");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d ", task_order[i]);
    }
    printf("\n");

    printf("Task completion times: ");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d ", task_comp_time[i]);
    }
    printf("\n");

    printf("Total execution time: %d\n", total_exec_time);

    return 0;
}