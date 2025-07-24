//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <sched.h>
#include <time.h>

struct task {
    char name[20];
    int priority;
    int arrival_time;
    int service_time;
    int start_time;
    int end_time;
};

void schedule(struct task *tasks, int num_tasks, int time_quantum) {
    printf("Starting task scheduling...\n");
    struct sched_param param;
    param.sched_priority = 99;
    if (sched_setscheduler(0, SCHED_FIFO, &param)) {
        perror("Error setting scheduler");
        return;
    }
    int current_time = 0;
    while (1) {
        int remaining_tasks = 0;
        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].service_time > 0) {
                printf("Task %s with priority %d found.\n", tasks[i].name, tasks[i].priority);
                remaining_tasks = 1;
                if (tasks[i].start_time == -1) {
                    tasks[i].start_time = current_time;
                }
                if (tasks[i].service_time <= time_quantum) {
                    printf("Executing task %s for %d units of time.\n", tasks[i].name, tasks[i].service_time);
                    current_time += tasks[i].service_time;
                    tasks[i].service_time = 0;
                    tasks[i].end_time = current_time;
                } else {
                    printf("Executing task %s for %d units of time.\n", tasks[i].name, time_quantum);
                    current_time += time_quantum;
                    tasks[i].service_time -= time_quantum;
                }
            }
        }
        if (!remaining_tasks) {
            break;
        }
    }
}

int main() {
    struct task tasks[] = {
        {"Task1", 1, 0, 3, -1, -1},
        {"Task2", 2, 2, 5, -1, -1},
        {"Task3", 3, 4, 2, -1, -1},
        {"Task4", 4, 6, 4, -1, -1},
    };
    int num_tasks = sizeof(tasks) / sizeof(tasks[0]);
    int time_quantum = 2;
    schedule(tasks, num_tasks, time_quantum);
    printf("Task scheduling complete.\n");
    printf("Task  | Priority | Arrival Time | Service Time | Start Time | End Time\n");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%-6s| %-9d| %-13d| %-13d| %-11d| %-8d\n",
               tasks[i].name, tasks[i].priority, tasks[i].arrival_time, tasks[i].service_time,
               tasks[i].start_time, tasks[i].end_time);
    }
    return 0;
}