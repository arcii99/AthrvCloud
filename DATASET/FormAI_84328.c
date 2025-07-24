//FormAI DATASET v1.0 Category: Task Scheduler ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAX_TASKS 100
#define TASK_STACK_SIZE 1024*1024

typedef struct {
    void (*function)(void*);
    void* args;
    int period;
    int releases;
    char* stack_pointer;
    char* stack_base;
} task_t;

int task_count = 0;
task_t tasks[MAX_TASKS];

void init_task(task_t* task, void (*function)(void*), void* args, int period, int releases) {
    task->function = function;
    task->args = args;
    task->period = period;
    task->releases = releases;
    task->stack_pointer = (char*)malloc(TASK_STACK_SIZE) + TASK_STACK_SIZE;
    task->stack_base = task->stack_pointer;
}

void delete_task(task_t* task) {
    free(task->stack_base - TASK_STACK_SIZE);
}

void execute_task(task_t* task) {
    task->function(task->args);
    task->releases--;
}

void run_task(task_t* task) {
    if(task->releases > 0) {
        execute_task(task);
    }
}

void add_task(void (*function)(void*), void* args, int period, int releases) {
    if(task_count < MAX_TASKS) {
        task_t* task = &tasks[task_count];
        init_task(task, function, args, period, releases);
        task_count++;
    }
}

void delete_all_tasks() {
    for(int i = 0; i < task_count; i++) {
        delete_task(&tasks[i]);
    }
    task_count = 0;
}

void scheduler() {
    while(1) {
        for(int i = 0; i < task_count; i++) {
            task_t* task = &tasks[i];
            if(task->period && (task->releases > 0)) {
                task->period--;
                if(task->period == 0) {
                    task->period = tasks[i].period;
                    run_task(task);
                }
            }
        }
        usleep(1000);
    }
}

void task_1(void* args) {
    printf("Task 1\n");
}

void task_2(void* args) {
    printf("Task 2\n");
}

void task_3(void* args) {
    printf("Task 3\n");
}

int main() {
    add_task(task_1, NULL, 10, 5);
    add_task(task_2, NULL, 20, 10);
    add_task(task_3, NULL, 30, 15);
    scheduler();
    delete_all_tasks();
    return 0;
}