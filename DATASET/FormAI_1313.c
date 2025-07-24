//FormAI DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_DURATION 10
#define MIN_INTERVAL 1
#define MAX_INTERVAL 5

typedef struct {
    int id;
    int duration;
    int interval;
    time_t last_execute_time;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void create_task(int duration, int interval) {
    if(num_tasks < MAX_TASKS) {
        tasks[num_tasks].id = num_tasks+1;
        tasks[num_tasks].duration = duration;
        tasks[num_tasks].interval = interval;
        tasks[num_tasks].last_execute_time = time(NULL);
        num_tasks++;
        printf("Task created with id %d, duration %d, interval %d\n", num_tasks, duration, interval);
    } else {
        printf("Task limit reached, cannot create any more tasks\n");
    }
}

void execute_task(Task *task) {
    printf("Executing task %d with duration %d\n", task->id, task->duration);
    // do some work here
    task->last_execute_time = time(NULL);
}

int main() {
    srand(time(NULL)); // seed random number generator
    for(int i=0; i<MAX_TASKS; i++) {
        int duration = rand() % MAX_DURATION + 1;
        int interval = rand() % (MAX_INTERVAL-MIN_INTERVAL+1) + MIN_INTERVAL;
        create_task(duration, interval);
    }

    while(1) {
        for(int i=0; i<num_tasks; i++) {
            time_t current_time = time(NULL);
            double diff_time = difftime(current_time, tasks[i].last_execute_time);
            if(diff_time >= tasks[i].interval) {
                execute_task(&tasks[i]);
            }
        }
    }

    return 0;
}