//FormAI DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 5

typedef struct {
    int id; // task ID
    int priority; // task priority
    int execution_time; // time needed to execute the task
    bool executed; // true if task has already been executed
} Task;

Task task_scheduler[MAX_TASKS];
int task_count = 0;

void add_task(int priority, int execution_time) {
    if (task_count < MAX_TASKS) {
        Task new_task;
        new_task.id = task_count + 1;
        new_task.priority = priority;
        new_task.execution_time = execution_time;
        new_task.executed = false;
        
        task_scheduler[task_count] = new_task;
        task_count++;
        printf("New task added to scheduler: ID %d, Priority %d, Execution Time %d\n", new_task.id, new_task.priority, new_task.execution_time);
    } else {
        printf("Task scheduler is full. Cannot add new task.\n");
    }
}

void execute_task() {
    int highest_priority_id = -1;
    int highest_priority = -1;
    
    // Find the task with highest priority that hasn't been executed yet
    for (int i = 0; i < task_count; i++) {
        if (!task_scheduler[i].executed && task_scheduler[i].priority > highest_priority) {
            highest_priority_id = i;
            highest_priority = task_scheduler[i].priority;
        }
    }
    
    if (highest_priority_id != -1) {
        Task task = task_scheduler[highest_priority_id];
        printf("Executing task: ID %d, Priority %d, Execution Time %d\n", task.id, task.priority, task.execution_time);
        task.executed = true;
    } else {
        printf("No pending tasks to execute.\n");
    }
}

int main() {
    // Generate random tasks
    srand(2022);
    for (int i = 0; i < MAX_TASKS; i++) {
        int priority = rand() % (MAX_PRIORITY + 1);
        int execution_time = rand() % 10 + 1;
        add_task(priority, execution_time);
    }
    
    // Execute tasks in priority order
    for (int i = 0; i < MAX_TASKS; i++) {
        execute_task();
    }
    
    return 0;
}