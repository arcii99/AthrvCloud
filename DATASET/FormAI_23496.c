//FormAI DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TASK_COUNT 10
#define MAX_PRIORITY 5
#define MAX_INTERVAL 10

typedef struct {
    int id;
    int priority;
    int interval;
    time_t last_run;
} task_t;

void run_task(task_t *task) {
    printf("Running task %d with priority %d\n", task->id, task->priority);
    task->last_run = time(NULL);
}

int compare_tasks(const void *a, const void *b) {
    task_t *task1 = (task_t*)a;
    task_t *task2 = (task_t*)b;
    double priority_diff = task2->priority - task1->priority;
    double time_diff = (difftime(task1->last_run, task2->last_run))/task1->interval - (difftime(time(NULL), task2->last_run))/task2->interval;
    return (priority_diff > 0) ? 1 :
           (priority_diff < 0) ? -1 :
           (time_diff > 0) ? 1 :
           (time_diff < 0) ? -1 :
           0 ;
}

int main() {
    task_t tasks[TASK_COUNT];
    for (int i = 0; i < TASK_COUNT; i++) {
        tasks[i].id = i;
        tasks[i].interval = rand() % MAX_INTERVAL + 1;
        tasks[i].priority = rand() % MAX_PRIORITY + 1;
        tasks[i].last_run = time(NULL) - (tasks[i].interval * rand() % 5 + 1);
    }

    while(1) {
        qsort(tasks, TASK_COUNT, sizeof(task_t), compare_tasks);
        run_task(&tasks[0]);
        sleep(1); // in seconds
    }
    return 0;
}