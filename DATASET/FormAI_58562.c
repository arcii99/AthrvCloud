//FormAI DATASET v1.0 Category: Task Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    int interval;
    int count;
    void (*func)(void);
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(int interval, void (*func)(void)) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: maximum number of tasks reached.\n");
        exit(1);
    }

    tasks[num_tasks].interval = interval;
    tasks[num_tasks].count = 0;
    tasks[num_tasks].func = func;
    num_tasks++;
}

void handle_signal(int sig) {
    printf("Exiting...\n");
    exit(0);
}

void handle_alarm(int sig) {
    int i;
    for (i = 0; i < num_tasks; i++) {
        if (tasks[i].count == tasks[i].interval) {
            tasks[i].func();
            tasks[i].count = 0;
        }
        else {
            tasks[i].count++;
        }
    }
}

void say_hello() {
    printf("Hello, world!\n");
}

void print_time() {
    time_t now = time(NULL);
    printf("The current time is %s", ctime(&now));
}

int main() {
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);
    signal(SIGALRM, handle_alarm);

    add_task(5, say_hello);
    add_task(10, print_time);

    while (1) {
        pause();
    }

    return 0;
}