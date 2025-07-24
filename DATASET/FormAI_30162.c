//FormAI DATASET v1.0 Category: Task Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

#define MAX_TASKS 10

typedef struct {
    bool active;
    int time;
    void (*func)(void);
} task_t;

int current_task = -1;
task_t task_list[MAX_TASKS];

void add_task(int time, void (*func)(void)) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (!task_list[i].active) {
            task_list[i].active = true;
            task_list[i].time = time;
            task_list[i].func = func;
            return;
        }
    }
}

void signal_handler(int sig) {
    if (sig == SIGALRM) {
        for (int i = 0; i < MAX_TASKS; i++) {
            if (task_list[i].active) {
                task_list[i].time--;
                if (task_list[i].time == 0) {
                    current_task = i;
                    task_list[i].func();
                    task_list[i].active = false;
                    current_task = -1;
                }
            }
        }
    }
}

void task_1() {
    printf("Task 1 executed!\n");
}

void task_2() {
    printf("Task 2 executed!\n");
}

int main() {
    signal(SIGALRM, signal_handler);

    add_task(5, task_1);
    add_task(10, task_2);

    while (true) {
        alarm(1);
        pause();
        if (current_task != -1) {
            printf("Task %d completed\n", current_task);
        }
    }

    return 0;
}