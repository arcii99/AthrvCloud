//FormAI DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TASKS 10 // Max number of tasks in task scheduler
#define MAX_PRIORITY 5 // Max priority of tasks

// Task entry struct
typedef struct task_entry {
    int priority;
    char task_name[20];
    void (*task_func)(void);
} task_entry;

task_entry task_list[MAX_TASKS]; // Array to store task entries
int num_tasks = 0; // Current number of tasks in task scheduler

// Function to add a task to task scheduler
void add_task(int priority, char* task_name, void (*task_func)(void)) {
    // Check if max number of tasks is already reached
    if (num_tasks >= MAX_TASKS) {
        printf("Task scheduler is full! Cannot add any more tasks.\n");
        return;
    }
    // Check if entered priority is within valid range
    if (priority < 1 || priority > MAX_PRIORITY) {
        printf("Invalid priority entered! Priority should be between 1 and %d.\n", MAX_PRIORITY);
        return;
    }
    // Add task entry to the task list array
    task_entry new_task = { priority, {0}, task_func };
    sprintf(new_task.task_name, "%s", task_name);
    task_list[num_tasks] = new_task;
    num_tasks++;
}

// Function to remove a task from task scheduler
void remove_task(char* task_name) {
    // Search for task entry with matching task name and remove it
    int i, j;
    for (i = 0; i < num_tasks; i++) {
        if (strcmp(task_list[i].task_name, task_name) == 0) {
            for (j = i; j < num_tasks - 1; j++) {
                task_list[j] = task_list[j + 1];
            }
            num_tasks--;
            printf("Task \"%s\" removed from task scheduler.\n", task_name);
            return;
        }
    }
    printf("Task \"%s\" not found in task scheduler!\n", task_name);
}

// Function to execute all tasks in the task list based on priority (higher priority tasks first)
void execute_tasks() {
    int i, j;
    for (i = MAX_PRIORITY; i >= 1; i--) {
        for (j = 0; j < num_tasks; j++) {
            if (task_list[j].priority == i) {
                printf("Executing task \"%s\"...\n", task_list[j].task_name);
                task_list[j].task_func(); // Call task function
            }
        }
    }
}

// Sample task functions
void task1() {
    printf("Task 1 executed!\n");
}

void task2() {
    printf("Task 2 executed!\n");
}

void task3() {
    printf("Task 3 executed!\n");
}

int main() {
    add_task(3, "Task 1", &task1);
    add_task(1, "Task 2", &task2);
    add_task(2, "Task 3", &task3);
    remove_task("Task 1");
    execute_tasks();
    return 0;
}