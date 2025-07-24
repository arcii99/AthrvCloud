//FormAI DATASET v1.0 Category: Task Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME_LEN 100
#define MAX_PRIORITY 3
#define MAX_TIME 10

typedef struct {
    char name[MAX_NAME_LEN];
    int priority;
    int time;
    void (*func)();
} task;

task task_list[MAX_TASKS];
int n_tasks = 0;

void add_task(char* name, int priority, int time, void (*func)()) {
    if(n_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }
    task t;
    strcpy(t.name, name);
    t.priority = priority;
    t.time = time;
    t.func = func;
    task_list[n_tasks++] = t;
}

void run_task(task t) {
    printf("Running task %s (priority=%d, time=%d)...\n", t.name, t.priority, t.time);
    t.func();
}

void schedule_tasks() {
    int time = 0;
    int i, j;
    while(time < MAX_TIME) {
        printf("Time=%d\n", time);
        for(i = MAX_PRIORITY-1; i >= 0; i--) {
            for(j = 0; j < n_tasks; j++) {
                if(task_list[j].priority == i && task_list[j].time > 0) {
                    run_task(task_list[j]);
                    task_list[j].time--;
                    break;
                }
            }
        }
        time++;
    }
}

void task1() {
    printf("Task 1\n");
}
void task2() {
    printf("Task 2\n");
}
void task3() {
    printf("Task 3\n");
}

int main() {
    srand(time(NULL));
    add_task("Task 1", rand() % MAX_PRIORITY, rand() % MAX_TIME, task1);
    add_task("Task 2", rand() % MAX_PRIORITY, rand() % MAX_TIME, task2);
    add_task("Task 3", rand() % MAX_PRIORITY, rand() % MAX_TIME, task3);
    schedule_tasks();
    return 0;
}