//FormAI DATASET v1.0 Category: Task Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 20

// Task structure
typedef struct Task {
    char name[MAX_NAME_LENGTH];
    int priority;
    int time_left;
} Task;

// Task scheduler structure
typedef struct TaskScheduler {
    Task tasks[MAX_TASKS];
    int num_tasks;
} TaskScheduler;

// Function to add a task to the scheduler
void add_task(TaskScheduler* scheduler, char* name, int priority, int time_left) {
    if (scheduler->num_tasks < MAX_TASKS) {
        Task new_task = {
            .priority = priority,
            .time_left = time_left
        };
        for (int i = 0; i < MAX_NAME_LENGTH; i++) {
            new_task.name[i] = name[i];
            if (name[i] == '\0') {
                break;
            }
        }
        int index = scheduler->num_tasks;
        while (index > 0 && new_task.priority > scheduler->tasks[index - 1].priority) {
            scheduler->tasks[index] = scheduler->tasks[index - 1];
            index--;
        }
        scheduler->tasks[index] = new_task;
        scheduler->num_tasks++;
    } else {
        printf("Task scheduler is full\n");
    }
}

// Function to remove the highest priority task from the scheduler
void remove_highest_priority_task(TaskScheduler* scheduler) {
    if (scheduler->num_tasks > 0) {
        printf("Removing task %s\n", scheduler->tasks[0].name);
        for (int i = 0; i < scheduler->num_tasks - 1; i++) {
            scheduler->tasks[i] = scheduler->tasks[i + 1];
        }
        scheduler->num_tasks--;
    } else {
        printf("Task scheduler is empty\n");
    }
}

// Function to print the tasks in the scheduler
void print_tasks(TaskScheduler* scheduler) {
    printf("Tasks in scheduler:\n");
    for (int i = 0; i < scheduler->num_tasks; i++) {
        Task* task = &scheduler->tasks[i];
        printf("%d: %s (%d)\n", i + 1, task->name, task->priority);
    }
}

int main() {
    TaskScheduler scheduler = {
        .num_tasks = 0
    };

    add_task(&scheduler, "Task 1", 3, 10);
    add_task(&scheduler, "Task 2", 2, 5);
    add_task(&scheduler, "Task 3", 1, 15);
    print_tasks(&scheduler);

    remove_highest_priority_task(&scheduler);
    print_tasks(&scheduler);

    add_task(&scheduler, "Task 4", 4, 8);
    print_tasks(&scheduler);

    return 0;
}