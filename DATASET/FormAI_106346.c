//FormAI DATASET v1.0 Category: Task Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 50

typedef struct {
    int id;
    char* name;
    int interval; //In seconds
    time_t last_run; //Last time task was executed
    void (*func)(void);
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void register_task(char* name, int interval, void (*func)(void)) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks exceeded\n");
        return;
    }
    tasks[num_tasks].id = num_tasks;
    tasks[num_tasks].name = name;
    tasks[num_tasks].interval = interval;
    tasks[num_tasks].last_run = time(NULL);
    tasks[num_tasks].func = func;
    num_tasks++;
}

void task_handler(int sig) {
    time_t current_time = time(NULL);
    int i;
    for (i = 0; i < num_tasks; i++) {
        if (current_time - tasks[i].last_run >= tasks[i].interval) {
            tasks[i].func();
            tasks[i].last_run = current_time;
        }
    }
}

void uptime_task() {
    printf("Uptime: %d seconds\n", (int)time(NULL));
}

void hello_task() {
    printf("Hello, world!\n");
}

int main() {
    register_task("Uptime", 5, uptime_task);
    register_task("Hello", 2, hello_task);

    //Setup task scheduler timer
    struct sigaction sa;
    sa.sa_handler = task_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("Error setting up signal handler");
        exit(1);
    }
    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("Error setting up timer execution");
        exit(1);
    }

    while(1) {
        //Do other stuff while tasks are running
        printf("Waiting for tasks...\n");
        sleep(1);
    }
    return 0;
}