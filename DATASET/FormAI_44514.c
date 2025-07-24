//FormAI DATASET v1.0 Category: Task Scheduler ; Style: synchronous
#include <stdio.h>

#define NUM_TASKS 5
#define MAX_TASK_NAME_LEN 20

typedef void (*Task)();

typedef struct {
    Task task_func;
    char name[MAX_TASK_NAME_LEN];
    int priority;
    int period;
    int run_counter;
} TaskDescriptor;

TaskDescriptor task_descriptors[NUM_TASKS];

// dummy task functions
void task_1() {
    printf("Task 1 running.\n");
}

void task_2() {
    printf("Task 2 running.\n");
}

void task_3() {
    printf("Task 3 running.\n");
}

void task_4() {
    printf("Task 4 running.\n");
}

void task_5() {
    printf("Task 5 running.\n");
}

void schedule_tasks() {
    int i;
    for (i = 0; i < NUM_TASKS; i++) {
        TaskDescriptor *task = &task_descriptors[i];
        if (task->run_counter == 0 || (task->run_counter > 0 && task->run_counter % task->period == 0)) {
            task->task_func();
        }
        task->run_counter++;
    }
}

int main() {
    // initialize task descriptors
    task_descriptors[0].task_func = task_1;
    task_descriptors[0].priority = 2;
    task_descriptors[0].period = 2;
    snprintf(task_descriptors[0].name, MAX_TASK_NAME_LEN, "Task 1");

    task_descriptors[1].task_func = task_2;
    task_descriptors[1].priority = 3;
    task_descriptors[1].period = 3;
    snprintf(task_descriptors[1].name, MAX_TASK_NAME_LEN, "Task 2");

    task_descriptors[2].task_func = task_3;
    task_descriptors[2].priority = 1;
    task_descriptors[2].period = 5;
    snprintf(task_descriptors[2].name, MAX_TASK_NAME_LEN, "Task 3");

    task_descriptors[3].task_func = task_4;
    task_descriptors[3].priority = 4;
    task_descriptors[3].period = 1;
    snprintf(task_descriptors[3].name, MAX_TASK_NAME_LEN, "Task 4");

    task_descriptors[4].task_func = task_5;
    task_descriptors[4].priority = 2;
    task_descriptors[4].period = 4;
    snprintf(task_descriptors[4].name, MAX_TASK_NAME_LEN, "Task 5");

    // run tasks
    int i;
    for (i = 0; i < 10; i++) {
        printf("Tick %d:\n", i);
        schedule_tasks();
        printf("\n");
    }

    return 0;
}