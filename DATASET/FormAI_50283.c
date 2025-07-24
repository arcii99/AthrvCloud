//FormAI DATASET v1.0 Category: Task Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    int id;
    int priority;
    bool completed;
    int estimated_time;
} Task;

void initialize_tasks(Task tasks[], int num_tasks);
int get_highest_priority_task(Task tasks[], int num_tasks);
void execute_task(Task tasks[], int task_index);

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    // Initialize tasks
    initialize_tasks(tasks, MAX_TASKS);
    
    // Add some random tasks
    srand(time(NULL));
    while (num_tasks < MAX_TASKS) {
        int i = rand() % MAX_TASKS;
        if (tasks[i].estimated_time == 0) {
            tasks[i].estimated_time = rand() % 10 + 1; // 1-10 seconds
            tasks[i].priority = rand() % 3 + 1; // 1-3 priority level
            tasks[i].id = num_tasks + 1; // Unique ID
            num_tasks++;
            printf("Added task #%d with priority %d and estimated time %d seconds.\n", tasks[i].id, tasks[i].priority, tasks[i].estimated_time);
        }
    }
    
    // Execute tasks based on priority
    int total_time = 0;
    while (true) {
        int task_index = get_highest_priority_task(tasks, MAX_TASKS);
        if (task_index == -1) {
            break; // No more tasks to execute
        }
        execute_task(tasks, task_index);
        total_time += tasks[task_index].estimated_time;
        printf("Task #%d completed in %d seconds. Total time elapsed: %d seconds.\n", tasks[task_index].id, tasks[task_index].estimated_time, total_time);
    }
    
    return 0;
}

void initialize_tasks(Task tasks[], int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        tasks[i].id = 0;
        tasks[i].priority = 0;
        tasks[i].completed = false;
        tasks[i].estimated_time = 0;
    }
}

int get_highest_priority_task(Task tasks[], int num_tasks) {
    int highest_priority = -1;
    int task_index = -1;
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].estimated_time > 0 && tasks[i].priority > highest_priority && !tasks[i].completed) {
            highest_priority = tasks[i].priority;
            task_index = i;
        }
    }
    return task_index;
}

void execute_task(Task tasks[], int task_index) {
    tasks[task_index].estimated_time = 0; // Set estimated time to 0 to mark as completed
    tasks[task_index].completed = true; // Mark task as completed
}