//FormAI DATASET v1.0 Category: Task Scheduler ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 20

typedef struct Task {
    char name[MAX_NAME_LENGTH];
    int interval;
    int remaining_time;
    bool completed;
} Task;

Task task_list[MAX_TASKS];
int num_tasks = 0;

void add_task(char name[], int interval) {
    if (num_tasks == MAX_TASKS) {
        printf("Error: maximum number of tasks reached.\n");
        return;
    }
    Task new_task;
    snprintf(new_task.name, MAX_NAME_LENGTH, "%s", name);
    new_task.interval = interval;
    new_task.remaining_time = interval;
    new_task.completed = false;
    task_list[num_tasks] = new_task;
    num_tasks++;
}

void print_tasks() {
    printf("Task List:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s: %d seconds, %d seconds remaining\n", task_list[i].name, task_list[i].interval, task_list[i].remaining_time);
    }
}

void update_task_times(int seconds) {
    for (int i = 0; i < num_tasks; i++) {
        if (!task_list[i].completed) {
            task_list[i].remaining_time -= seconds;
            if (task_list[i].remaining_time <= 0) {
                task_list[i].remaining_time = task_list[i].interval;
                printf("%s completed!\n", task_list[i].name);
                task_list[i].completed = true;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    
    add_task("Clean Room", 300);
    add_task("Do Laundry", 600);
    add_task("Study for Exam", 1800);
    add_task("Exercise", 900);
    
    print_tasks();
    
    int total_seconds = 3600;
    int seconds_left = total_seconds;
    while (seconds_left > 0) {
        int interval = rand() % (seconds_left / 2) + 1;
        printf("Time until next check: %d seconds\n", interval);
        update_task_times(interval);
        print_tasks();
        seconds_left -= interval;
    }
    
    printf("All tasks completed!\n");
    
    return 0;
}