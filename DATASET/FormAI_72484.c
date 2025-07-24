//FormAI DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 10           // maximum number of tasks
#define MAX_PRIORITY 10        // maximum priority level
#define TASK_NAME_LENGTH 20    // maximum length of task name

typedef struct {               // structure to hold a task's information
    char name[TASK_NAME_LENGTH];
    int priority;
    int interval;
    time_t last_run;
    void (*function)(void);
} Task;

Task task_list[MAX_TASKS];      // array to hold all tasks
int task_count = 0;             // current number of tasks

// function to add a task to the task list
void add_task(char name[], int priority, int interval, void (*function)(void)) {
    if (task_count >= MAX_TASKS) {
        printf("Cannot add new task. Task list is full.\n");
        return;
    }
    Task new_task;
    strncpy(new_task.name, name, TASK_NAME_LENGTH);
    new_task.priority = priority;
    new_task.interval = interval;
    new_task.last_run = 0;
    new_task.function = function;
    task_list[task_count++] = new_task;
    printf("Task \"%s\" added with priority %d and interval %d seconds.\n", 
           name, priority, interval);
}

// function to remove a task from the task list
void remove_task(int index) {
    if (index < 0 || index >= task_count) {
        printf("Cannot remove task. Invalid index.\n");
        return;
    }
    printf("Task \"%s\" removed.\n", task_list[index].name);
    for (int i = index; i < task_count - 1; i++) {
        task_list[i] = task_list[i + 1];
    }
    task_count--;
}

// function to run all tasks that are due
void run_due_tasks() {
    time_t current_time = time(NULL);
    for (int i = 0; i < task_count; i++) {
        Task task = task_list[i];
        if (difftime(current_time, task.last_run) >= task.interval) {
            task.function();
            task.last_run = current_time;
            task_list[i] = task;
        }
    }
}

// example task function
void task_function1() {
    printf("Task 1 has run!\n");
}

// example task function 2
void task_function2() {
    printf("Task 2 has run!\n");
}

int main() {
    add_task("Task 1", 1, 1, task_function1);
    add_task("Task 2", 5, 5, task_function2);

    while (true) {
        run_due_tasks();
    }

    return 0;
}