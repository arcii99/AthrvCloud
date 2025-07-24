//FormAI DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TIME 100

void task_one(void) {
    printf("Executing Task One...\n");
}

void task_two(void) {
    printf("Executing Task Two...\n");
}

void task_three(void) {
    printf("Executing Task Three...\n");
}

void task_four(void) {
    printf("Executing Task Four...\n");
}

typedef struct {
    void (*task_function)(void);
    int time;
} Task;

Task task_list[MAX_TASKS];
int num_tasks = 0;
int total_time = 0;

void schedule_task(void (*task_function)(void), int time) {
    if (num_tasks < MAX_TASKS) {
        Task new_task = { task_function, time };
        task_list[num_tasks] = new_task;
        num_tasks++;
        total_time += time;
        printf("Task Scheduled!\n");
    } else {
        printf("Task Scheduler Full!\n");
    }
}

void run_task_scheduler(void) {
    printf("Running Task Scheduler...\n");
    int current_time = 0;
    while (current_time < total_time) {
        for (int i = 0; i < num_tasks; i++) {
            Task current_task = task_list[i];
            if (current_time >= current_task.time) {
                current_task.task_function();
                current_time -= current_task.time;
                for (int j = i; j < num_tasks - 1; j++) {
                    task_list[j] = task_list[j + 1];
                }
                num_tasks--;
            }
        }
        current_time++;
    }
}

int main(void) {
    srand(time(NULL));
    int task_time;
    for (int i = 0; i < MAX_TASKS; i++) {
        task_time = rand() % (MAX_TIME + 1);
        switch (rand() % 4) {
            case 0:
                schedule_task(task_one, task_time);
                break;
            case 1:
                schedule_task(task_two, task_time);
                break;
            case 2:
                schedule_task(task_three, task_time);
                break;
            case 3:
                schedule_task(task_four, task_time);
                break;
        }
    }
    run_task_scheduler();
    return 0;
}