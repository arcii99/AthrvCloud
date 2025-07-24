//FormAI DATASET v1.0 Category: Task Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TASKS 10
#define MAX_PRIORITY 10
#define TIME_QUANTUM 1
#define MAX_RUNTIME 5

typedef struct {
    int id;
    int priority;
    int arrival_time;
    int burst_time;
    int remaining_time;
} Task;

Task tasks[NUM_TASKS];

void generate_tasks() {
    srand(time(NULL));
    for (int i = 0; i < NUM_TASKS; i++) {
        tasks[i].id = i;
        tasks[i].priority = rand() % MAX_PRIORITY + 1;
        tasks[i].arrival_time = rand() % 10;
        tasks[i].burst_time = rand() % MAX_RUNTIME + 1;
        tasks[i].remaining_time = tasks[i].burst_time;
    }
}

void display_tasks() {
    printf("Id\tPriority\tArrival Time\tBurst Time\n");
    for (int i = 0; i < NUM_TASKS; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", tasks[i].id, tasks[i].priority, tasks[i].arrival_time, tasks[i].burst_time);
    }
}

int get_next_task(int current_time) {
    int next_task = -1;
    int highest_priority = MAX_PRIORITY + 1;
    for (int i = 0; i < NUM_TASKS; i++) {
        if (tasks[i].arrival_time <= current_time && tasks[i].remaining_time > 0 && tasks[i].priority < highest_priority) {
            next_task = i;
            highest_priority = tasks[i].priority;
        }
    }
    return next_task;
}

void run_tasks() {
    int current_time = 0;
    int running_task = -1;
    int num_completed = 0;
    while (num_completed < NUM_TASKS) {
        running_task = get_next_task(current_time);
        if (running_task == -1) {
            printf("No task available at %d\n", current_time);
            current_time++;
            continue;
        }
        printf("Executing task %d at time %d\n", tasks[running_task].id, current_time);
        int run_time = (tasks[running_task].remaining_time < TIME_QUANTUM) ? tasks[running_task].remaining_time : TIME_QUANTUM;
        tasks[running_task].remaining_time -= run_time;
        current_time += run_time;
        if (tasks[running_task].remaining_time == 0) {
            num_completed++;
            printf("Task %d is completed at time %d\n", tasks[running_task].id, current_time);
        }
    }
}

int main() {
    generate_tasks();
    printf("Initial task list:\n");
    display_tasks();
    run_tasks();
    return 0;
}