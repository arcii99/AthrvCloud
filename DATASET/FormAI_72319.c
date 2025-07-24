//FormAI DATASET v1.0 Category: Task Scheduler ; Style: protected
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM_TASKS 10

typedef struct Task {
    int id;
    int priority;
    bool is_activated;
    void (*func_ptr)(void);
} Task;

Task task_list[MAX_NUM_TASKS];
int num_tasks = 0;

Task* get_next_task() {
    Task* highest_priority_task = NULL;
    for (int i = 0; i < num_tasks; i++) {
        Task* task = &task_list[i];
        if (!task->is_activated) {
            continue;
        }
        if (highest_priority_task == NULL || task->priority > highest_priority_task->priority) {
            highest_priority_task = task;
        }
    }
    return highest_priority_task;
}

void task_scheduler() {
    while (true) {
        Task* task = get_next_task();
        if (task == NULL) {
            continue;
        }
        task->func_ptr();
    }
}

void add_task(int priority, void (*func_ptr)(void)) {
    if (num_tasks >= MAX_NUM_TASKS) {
        printf("Error: Maximum number of tasks already added.\n");
        return;
    }
    Task* task = &task_list[num_tasks];
    task->id = num_tasks;
    task->priority = priority;
    task->is_activated = true;
    task->func_ptr = func_ptr;
    num_tasks++;
    printf("Task added.\n");
}

void remove_task(int id) {
    bool found_task = false;
    for (int i = 0; i < num_tasks; i++) {
        Task* task = &task_list[i];
        if (task->id == id) {
            task->is_activated = false;
            found_task = true;
            break;
        }
    }
    if (found_task) {
        printf("Task removed.\n");
    } else {
        printf("Error: Task with id=%d not found.\n", id);
    }
}

void task1() {
    printf("Task1 running.\n");
}

void task2() {
    printf("Task2 running.\n");
}

int main() {
    printf("Creating task list...\n");
    add_task(2, &task1);
    add_task(1, &task2);

    printf("Starting task scheduler...\n");
    task_scheduler();

    return 0;
}