//FormAI DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef void (*task_func)(int);

typedef struct task {
    task_func func;
    int delay;
    int period;
    int exec_time;
    bool enabled;
} task_t;

task_t tasks[10];

void task1(int arg) {
    printf("Task 1 running with argument %d\n", arg);
}

void task2(int arg) {
    printf("Task 2 running with argument %d\n", arg);
}

void scheduler_init(void) {
    for(int i = 0; i < 10; i++) {
        tasks[i].func = NULL;
        tasks[i].delay = 0;
        tasks[i].period = 0;
        tasks[i].exec_time = 0;
        tasks[i].enabled = false;
    }
}

void scheduler_add_task(task_func func, int delay, int period) {
    for(int i = 0; i < 10; i++) {
        if(tasks[i].func == NULL) {
            tasks[i].func = func;
            tasks[i].delay = delay;
            tasks[i].period = period;
            tasks[i].enabled = true;
            break;
        }
    }
}

void scheduler_remove_task(task_func func) {
    for(int i = 0; i < 10; i++) {
        if(tasks[i].func == func) {
            tasks[i].func = NULL;
            tasks[i].delay = 0;
            tasks[i].period = 0;
            tasks[i].exec_time = 0;
            tasks[i].enabled = false;
            break;
        }
    }
}

void scheduler_run(void) {
    int time = 0;
    while(1) {
        printf("Time: %d\n", time);
        for(int i = 0; i < 10; i++) {
            if(tasks[i].func != NULL && tasks[i].enabled == true) {
                if(tasks[i].delay == 0) {
                    if(tasks[i].exec_time == 0) {
                        tasks[i].func(i);
                        tasks[i].exec_time = tasks[i].period;
                    } else {
                        tasks[i].exec_time--;
                    }
                } else {
                    tasks[i].delay--;
                }
            }
        }
        time++;
    }
}

int main(void) {
    scheduler_init();
    scheduler_add_task(task1, 0, 3);
    scheduler_add_task(task2, 1, 2);
    scheduler_remove_task(task2);
    scheduler_run();
    return 0;
}