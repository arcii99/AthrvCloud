//FormAI DATASET v1.0 Category: Task Scheduler ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_TASK_NAME_LENGTH 20

typedef struct {
    char name[MAX_TASK_NAME_LENGTH];
    int priority;
    void (*fun_ptr)();
} Task;

Task task_list[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, int priority, void (*fun_ptr)()) {
    if (num_tasks < MAX_TASKS) {
        Task task;
        snprintf(task.name, MAX_TASK_NAME_LENGTH, "%s", name);
        task.priority = priority;
        task.fun_ptr = fun_ptr;
        task_list[num_tasks++] = task;
    } else {
        printf("Task list is full\n");
    }
}

void run_task(Task task) {
    printf("Running task: %s\n", task.name);
    task.fun_ptr();
}

void scheduler() {
    int i, j;
    for (i = 0; i < num_tasks - 1; i++) {
        for (j = i + 1; j < num_tasks; j++) {
            if (task_list[j].priority > task_list[i].priority) {
                Task temp = task_list[i];
                task_list[i] = task_list[j];
                task_list[j] = temp;
            }
        }
    }
    for (i = 0; i < num_tasks; i++) {
        run_task(task_list[i]);
    }
}

void task1() {
    printf("This is task 1\n");
}

void task2() {
    printf("This is task 2\n");
}

void task3() {
    printf("This is task 3\n");
}

void task4() {
    printf("This is task 4\n");
}

int main() {
    srand(time(0));
    printf("Task Scheduler Demo\n");
    add_task("Task 1", rand() % 10, task1);
    add_task("Task 2", rand() % 10, task2);
    add_task("Task 3", rand() % 10, task3);
    add_task("Task 4", rand() % 10, task4);
    scheduler();
    return 0;
}