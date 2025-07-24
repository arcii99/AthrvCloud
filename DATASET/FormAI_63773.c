//FormAI DATASET v1.0 Category: Task Scheduler ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int interval;
    time_t last_run_time;
    void (*run_func)();
} Task;

Task task_list[MAX_TASKS]; // global array of Task structs
int num_tasks = 0; // number of tasks added

// function to handle tasks
void execute_task(Task task) {
    printf("Executing task '%s'\n", task.name);
    (*task.run_func)();
    task.last_run_time = time(NULL);
}

// function to add a new task to task_list
void add_task(char* name, int interval, void (*run_func)()) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached\n");
        return;
    }
    Task new_task;
    strcpy(new_task.name, name);
    new_task.interval = interval;
    new_task.last_run_time = 0;
    new_task.run_func = run_func;
    task_list[num_tasks] = new_task;
    num_tasks++;
    printf("Task '%s' added successfully\n", name);
}

// define tasks' functions
void task1() {
    printf("Task 1 executed\n");
}
void task2() {
    printf("Task 2 executed\n");
}

int main() {
    // add tasks to task_list
    add_task("Task 1", 5, &task1);
    add_task("Task 2", 10, &task2);
    
    // run scheduler
    while (1) { // infinite loop
        for (int i = 0; i < num_tasks; i++) {
            Task task = task_list[i];
            if (difftime(time(NULL), task.last_run_time) >= task.interval) {
                execute_task(task);
            }
        }
    }
    return 0;
}