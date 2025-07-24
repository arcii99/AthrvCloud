//FormAI DATASET v1.0 Category: Task Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    char name[20];
    int interval;
    time_t last_executed;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task(char name[], int interval) {
    if (task_count >= MAX_TASKS) {
        printf("Error: Too many tasks\n");
        return;
    }
  
    Task task;
    task.id = task_count;
    strcpy(task.name, name);
    task.interval = interval;
    task.last_executed = time(NULL);
    tasks[task_count] = task;
    task_count++;
  
    printf("Task added successfully!\n");
}

void execute_task(Task *task) {
    time_t curr_time = time(NULL);
    double elapsed_time = difftime(curr_time, task->last_executed);
  
    if (elapsed_time >= task->interval) {
        printf("Executing task %d: %s\n", task->id, task->name);
        task->last_executed = curr_time;
    }
}

int main() {
    add_task("Task 1", 5);
    add_task("Task 2", 10);
    add_task("Task 3", 15);
  
    while (1) {
        for (int i = 0; i < task_count; i++) {
            execute_task(&tasks[i]);
        }
        sleep(1); // wait for 1 second
    }
  
    return 0;
}