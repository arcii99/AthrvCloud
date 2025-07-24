//FormAI DATASET v1.0 Category: Task Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 5

typedef struct {
    int id;
    int priority;
    int duration;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(int priority, int duration) {
    if (task_count < MAX_TASKS) {
        task_list[task_count].id = task_count+1;
        task_list[task_count].priority = priority;
        task_list[task_count].duration = duration;
        printf("Task ID: %d | Priority: %d | Duration: %d\n", task_list[task_count].id, task_list[task_count].priority, task_list[task_count].duration);
        task_count++;
    } else {
        printf("Task list is full, please remove some tasks.\n");
    }
}

void schedule_task() {
    int i, j;
    int current_time = 0;
    int completed_tasks = 0;
    while (completed_tasks < task_count) {
        int highest_priority = 0;
        int highest_priority_task_index = -1;
        for (i = 0; i < task_count; i++) {
            Task task = task_list[i];
            if (task.duration > 0 && task.priority >= highest_priority) {
                highest_priority = task.priority;
                highest_priority_task_index = i;
            }
        }
        if (highest_priority_task_index == -1) {
            printf("No tasks to schedule at this time.\n");
        } else {
            Task highest_priority_task = task_list[highest_priority_task_index];
            printf("Current Time: %d | Scheduling Task | ID: %d | Priority: %d | Duration: %d\n", current_time, highest_priority_task.id, highest_priority_task.priority, highest_priority_task.duration);
            highest_priority_task.duration--;
            if (highest_priority_task.duration == 0) {
                printf("Task ID: %d has completed.\n", highest_priority_task.id);
                task_list[highest_priority_task_index].priority = 0;
                completed_tasks++;
            }
        }
        current_time++;
    }
    printf("All tasks have been completed.\n");
}

int main(int argc, char *argv[]) {
    srand(time(0));
    int i;
    printf("Creating tasks...\n");
    for (i = 0; i < MAX_TASKS; i++) {
        add_task(rand() % MAX_PRIORITY + 1, rand() % 10 + 1);
    }
    printf("\nScheduling tasks...\n");
    schedule_task();
    return 0;
}