//FormAI DATASET v1.0 Category: Task Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME_LEN 20

typedef enum {WAITING, RUNNING, FINISHED} task_status;

typedef struct {
    char name[MAX_NAME_LEN];
    task_status status;
    int duration;
    int time_remaining;
} task;

task task_list[MAX_TASKS];
int num_tasks;

void schedule_handler(int signum) {
    int i;
    for (i = 0; i < num_tasks; i++) {
        if (task_list[i].status == WAITING) {
            task_list[i].status = RUNNING;
            task_list[i].time_remaining = task_list[i].duration;
            printf("Task %s started\n", task_list[i].name);
            break;
        }
    }
}

void timer_handler(int signum) {
    int i;
    for (i = 0; i < num_tasks; i++) {
        if (task_list[i].status == RUNNING) {
            task_list[i].time_remaining--;
            if (task_list[i].time_remaining == 0) {
                task_list[i].status = FINISHED;
                printf("Task %s finished\n", task_list[i].name);
            }
        }
    }
}

int main() {
    int i;
    srand(time(NULL));
    num_tasks = rand() % MAX_TASKS + 1;
    printf("Number of tasks: %d\n", num_tasks);
    signal(SIGUSR1, schedule_handler);
    signal(SIGALRM, timer_handler);
    for (i = 0; i < num_tasks; i++) {
        sprintf(task_list[i].name, "Task %d", i);
        task_list[i].status = WAITING;
        task_list[i].duration = rand() % 10 + 1;
        printf("%s duration: %d\n", task_list[i].name, task_list[i].duration);
    }
    printf("Starting task scheduler...\n");
    while (1) {
        alarm(1);
        pause();
        int all_finished = 1;
        for (i = 0; i < num_tasks; i++) {
            if (task_list[i].status != FINISHED) {
                all_finished = 0;
            }
        }
        if (all_finished) break;
    }
    printf("All tasks finished\n");
    return 0;
}