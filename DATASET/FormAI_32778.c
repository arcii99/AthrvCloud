//FormAI DATASET v1.0 Category: Task Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define NUM_TASKS 3
#define NUM_REPEATS 4

typedef struct task {
    char *name;
    int time_interval;
    int task_id;
    int counter;
} task_t;

int num_tasks_complete = 0;

void task_handler(int sig_num) {
    num_tasks_complete++;
    printf("Task complete!\n");
}

void setup_task_handler(void (*handler)(int)) {
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("Error setting up task handler.");
        exit(EXIT_FAILURE);
    }
}

void schedule_task(task_t task) {
    printf("Scheduling task %d: %s\n", task.task_id, task.name);
    alarm(task.time_interval);
    printf("Waiting for task to complete...\n");
    while (num_tasks_complete < task.counter) {
        sleep(1);
    }
    num_tasks_complete = 0;
    printf("Task %d: %s complete!\n", task.task_id, task.name);
}

int main() {
    task_t tasks[NUM_TASKS] = {
        {"update_cache", 10, 1, NUM_REPEATS},
        {"send_email", 5, 2, NUM_REPEATS},
        {"calculate_stats", 15, 3, NUM_REPEATS}
    };
    setup_task_handler(task_handler);
    for (int i = 0; i < NUM_TASKS; i++) {
        for (int j = 0; j < NUM_REPEATS; j++) {
            printf("Executing cycle %d of task %d: %s\n", j+1, tasks[i].task_id, tasks[i].name);
            schedule_task(tasks[i]);
        }
    }
    printf("All tasks complete!\n");
    return 0;
}