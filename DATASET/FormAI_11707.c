//FormAI DATASET v1.0 Category: Task Scheduler ; Style: complete
#include<stdio.h>
#include<stdlib.h>

#define MAX_TASKS 10

typedef void (*TaskFunction)(void);

typedef struct {
    unsigned int delay; // delay in milliseconds
    TaskFunction task; // task to be executed
    unsigned int period; // period in milliseconds
} Task;

Task tasks[MAX_TASKS];
unsigned int numTasks = 0;

void delay(unsigned int milliseconds) {
    unsigned int ms = milliseconds * 1000;
    unsigned int start = clock();
    while (clock() < start + ms);
}

void addTask(unsigned int delay, TaskFunction task, unsigned int period) {
    Task t = { delay, task, period };
    tasks[numTasks++] = t;
}

void taskScheduler() {
    while (1) {
        for (unsigned int i = 0; i < numTasks; i++) {
            Task t = tasks[i];
            if (t.delay == 0) {
                t.task();
                t.delay = t.period;
            } else {
                t.delay--;
            }
            tasks[i] = t;
            delay(1);
        }
    }
}

void ledTask() {
    printf("LED task\n");
}

void buttonTask() {
    printf("Button task\n");
}

int main() {
    addTask(0, ledTask, 1000);
    addTask(0, buttonTask, 500);
    taskScheduler();
    return 0;
}