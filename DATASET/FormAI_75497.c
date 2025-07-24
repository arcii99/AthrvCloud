//FormAI DATASET v1.0 Category: Task Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void (*task)(void);
    unsigned long interval;
    unsigned long last_run;
} Task;

Task tasks[10];

unsigned char num_tasks = 0;

void add_task(void (*task)(void), unsigned long interval) {
    if (num_tasks >= 10) {
        perror("Too many tasks!");
        exit(-1);
    }

    tasks[num_tasks].task = task;
    tasks[num_tasks].interval = interval;
    tasks[num_tasks].last_run = 0;
    num_tasks++;
}

void execute_task(unsigned char task_index, unsigned long current_time) {
    tasks[task_index].task();
    tasks[task_index].last_run = current_time;
}

void run_tasks(unsigned long current_time) {
    int i;

    for (i = 0; i < num_tasks; i++) {
        if ((current_time - tasks[i].last_run) >= tasks[i].interval) {
            execute_task(i, current_time);
        }
    }
}

/* Example Tasks */
void task_1() {
    printf("Executing Task 1\n");
}

void task_2() {
    printf("Executing Task 2\n");
}

int main() {
    add_task(&task_1, 1000 /* 1 second */);
    add_task(&task_2, 2000 /* 2 seconds */);

    unsigned long current_time = 0;
    while (1) {
        run_tasks(current_time);
        current_time += 100; /* increment by 100ms */
    }

    return 0;
}