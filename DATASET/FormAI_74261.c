//FormAI DATASET v1.0 Category: Task Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <time.h>

#define NUM_TASKS 5
#define MAX_PRIORITY 99
#define MIN_PRIORITY 1

typedef struct Task {
    char name[20];
    int priority;
    int cpu_time;
} Task;

int main() {
    Task tasks[NUM_TASKS];
    int total_cpu_time = 0;

    // create tasks with random priority and cpu time
    for (int i = 0; i < NUM_TASKS; i++) {
        sprintf(tasks[i].name, "Task %d", i+1);
        tasks[i].priority = rand() % (MAX_PRIORITY - MIN_PRIORITY + 1) + MIN_PRIORITY;
        tasks[i].cpu_time = rand() % 10 + 1; // 1 - 10 seconds
        total_cpu_time += tasks[i].cpu_time;
    }

    // sort tasks in descending order of priority
    for (int i = 0; i < NUM_TASKS - 1; i++) {
        for (int j = 0; j < NUM_TASKS - i - 1; j++) {
            if (tasks[j].priority < tasks[j+1].priority) {
                Task temp = tasks[j];
                tasks[j] = tasks[j+1];
                tasks[j+1] = temp;
            }
        }
    }

    // create a CPU scheduler with SCHED_FIFO policy and maximum priority
    struct sched_param params;
    params.sched_priority = MAX_PRIORITY;
    if (sched_setscheduler(0, SCHED_FIFO, &params) == -1) {
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }

    // execute tasks in order of priority
    for (int i = 0; i < NUM_TASKS; i++) {
        clock_t start = clock(); // start timer
        printf("%s running...\n", tasks[i].name);
        while (((double)(clock() - start) / CLOCKS_PER_SEC) < tasks[i].cpu_time) {} // busy wait
    }

    // reset scheduler policy to default
    if (sched_setscheduler(0, SCHED_OTHER, &params) == -1) {
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }

    printf("All tasks completed! Total CPU time used: %d seconds.\n", total_cpu_time);
    return 0;
}