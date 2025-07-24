//FormAI DATASET v1.0 Category: Task Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    int time;
    bool is_done;
    void (*task_func)(void);
} Task;

Task task_queue[MAX_TASKS];
int num_tasks = 0;
int current_task_index = 0;

void add_task(int time, void (*task_func)(void)) {
    if (num_tasks >= MAX_TASKS) {
        printf("Could not add task, maximum number of tasks reached.\n");
        return;
    }

    Task task;
    task.id = num_tasks;
    task.time = time;
    task.is_done = false;
    task.task_func = task_func;
    task_queue[num_tasks] = task;
    num_tasks++;
}

void remove_task(int id) {
    int i;
    for (i = 0; i < num_tasks; i++) {
        if (task_queue[i].id == id) {
            task_queue[i].is_done = true;
            break;
        }
    }
}

void task1(void) {
    printf("Executing task 1...\n");
}

void task2(void) {
    printf("Executing task 2...\n");
}

void task3(void) {
    printf("Executing task 3...\n");
}

void task4(void) {
    printf("Executing task 4...\n");
}

void run_scheduler(int time_interval) {
    int count = 0;

    while (num_tasks > 0) {
        if (count == time_interval) {
            if (task_queue[current_task_index].is_done) {
                current_task_index++;
                if (current_task_index >= num_tasks) {
                    current_task_index = 0;
                }
            }
            task_queue[current_task_index].task_func();
            task_queue[current_task_index].is_done = true;
            count = 0;
        }

        count++;
        sleep(1);
    }
}

int main(void) {
    add_task(5, task1);
    add_task(10, task2);
    add_task(15, task3);
    add_task(20, task4);

    printf("Tasks added to scheduler.\n");

    run_scheduler(25);

    printf("Scheduler finished.\n");

    return 0;
}