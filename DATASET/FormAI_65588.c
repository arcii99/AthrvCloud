//FormAI DATASET v1.0 Category: Task Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <time.h>

#define MAX_TASKS 5

struct task {
    int id;
    int priority;
    int burst_time;
    int time_left;
    int arrival_time;
};

void task_scheduler() {
    struct task tasks[MAX_TASKS];
    int tasks_completed = 0;
    int current_task = -1;
    int current_time = 0;

    // initialize the tasks
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].id = i + 1;
        tasks[i].priority = rand() % 10;
        tasks[i].burst_time = rand() % 10 + 1;
        tasks[i].time_left = tasks[i].burst_time;
        tasks[i].arrival_time = rand() % 10;
    }

    printf("Task Scheduler\n");
    printf("=======================================\n");
    printf("ID\tPriority\tBurst Time\tArrival Time\n");
    printf("=======================================\n");

    for (int i = 0; i < MAX_TASKS; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", tasks[i].id, tasks[i].priority, tasks[i].burst_time, tasks[i].arrival_time);
    }

    printf("=======================================\n");

    // run the scheduler
    while (tasks_completed < MAX_TASKS) {
        int shortest = -1;

        for (int i = 0; i < MAX_TASKS; i++) {
            if (tasks[i].time_left > 0 && tasks[i].arrival_time <= current_time) {
                if (shortest == -1) {
                    shortest = i;
                } else if (tasks[i].priority < tasks[shortest].priority) {
                    shortest = i;
                }
            }
        }

        if (shortest != -1) {
            // switch tasks
            if (current_task != shortest) {
                printf("Switching from task %d to task %d at time %d\n", current_task + 1, shortest + 1, current_time);
                current_task = shortest;
            }

            // execute task for 1 time unit
            tasks[shortest].time_left--;
            current_time++;

            // check if task is complete
            if (tasks[shortest].time_left == 0) {
                printf("Task %d completed at time %d\n", shortest + 1, current_time);
                tasks_completed++;
            }
        } else {
            // no tasks available, idle for 1 time unit
            printf("Idle at time %d\n", current_time);
            current_time++;
        }
    }

    printf("All tasks completed at time %d\n", current_time);
}

int main() {
    task_scheduler();
    return 0;
}