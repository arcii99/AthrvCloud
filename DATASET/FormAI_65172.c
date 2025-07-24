//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_LEN 100

typedef struct {
    char name[MAX_TASK_LEN];
    int priority;
    void (*entry_point)(void);
    bool executed;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

int get_random_number(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

void task1() {
    printf("Executing task 1\n");
    tasks[0].executed = true;
}

void task2() {
    printf("Executing task 2\n");
    tasks[1].executed = true;
}

void task3() {
    printf("Executing task 3\n");
    tasks[2].executed = true;
}

void task4() {
    printf("Executing task 4\n");
    tasks[3].executed = true;
}

void task5() {
    printf("Executing task 5\n");
    tasks[4].executed = true;
}

void schedule() {
    printf("Scheduling tasks...\n");
    for (int i = 0; i < num_tasks; i++) {
        int task_idx = get_random_number(0, num_tasks-1);
        if (!tasks[task_idx].executed) {
            printf("Executing task %d\n", task_idx+1);
            tasks[task_idx].entry_point();
        }
    }
}

int main() {
    // Define and add tasks to the task list
    strcpy(tasks[0].name, "Task 1");
    tasks[0].priority = 1;
    tasks[0].entry_point = task1;
    tasks[0].executed = false;
    num_tasks++;

    strcpy(tasks[1].name, "Task 2");
    tasks[1].priority = 2;
    tasks[1].entry_point = task2;
    tasks[1].executed = false;
    num_tasks++;

    strcpy(tasks[2].name, "Task 3");
    tasks[2].priority = 3;
    tasks[2].entry_point = task3;
    tasks[2].executed = false;
    num_tasks++;

    strcpy(tasks[3].name, "Task 4");
    tasks[3].priority = 4;
    tasks[3].entry_point = task4;
    tasks[3].executed = false;
    num_tasks++;

    strcpy(tasks[4].name, "Task 5");
    tasks[4].priority = 5;
    tasks[4].entry_point = task5;
    tasks[4].executed = false;
    num_tasks++;

    // Schedule the tasks
    schedule();

    return 0;
}