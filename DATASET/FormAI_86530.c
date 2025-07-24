//FormAI DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct task {
    int id;
    int delay;
    int interval;
    void (*func)(void);
    bool enabled;
} task_t;

task_t tasks[4];

void task1(void) {
    printf("Task 1 Running...\n");
}

void task2(void) {
    printf("Task 2 Running...\n");
}

void task3(void) {
    printf("Task 3 Running...\n");
}

void task4(void) {
    printf("Task 4 Running...\n");
}

void taskScheduler(void) {
    for(int i = 0; i < 4; i++) {
        if(tasks[i].enabled && tasks[i].delay == 0) {
            tasks[i].func();
            tasks[i].delay = tasks[i].interval;
        }
        if(tasks[i].delay > 0) tasks[i].delay--;
    }
    sleep(1);
}

int main() {
    tasks[0] = (task_t) {1, 0, 1, &task1, true};
    tasks[1] = (task_t) {2, 2, 2, &task2, true};
    tasks[2] = (task_t) {3, 4, 3, &task3, true};
    tasks[3] = (task_t) {4, 1, 1, &task4, false};
    
    while(true) {
        taskScheduler();
    }
    
    return 0;
}