//FormAI DATASET v1.0 Category: Task Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

struct task {
    int id;
    int time;
};

void schedule_task(int id, int time, struct task *tasks, int *num_tasks) {
    if (*num_tasks >= MAX_TASKS) {
        printf("Cannot schedule task: maximum number of tasks reached.\n");
        return;
    }
    tasks[*num_tasks].id = id;
    tasks[*num_tasks].time = time;
    *num_tasks += 1;
}

void run_task(struct task *tasks, int *num_tasks) {
    if (*num_tasks == 0) {
        printf("No tasks to run.\n");
        return;
    }
    int min_time = tasks[0].time;
    int min_index = 0;
    for (int i = 1; i < *num_tasks; i++) {
        if (tasks[i].time < min_time) {
            min_time = tasks[i].time;
            min_index = i;
        }
    }
    printf("Running task %d for %d seconds...\n", tasks[min_index].id, tasks[min_index].time);
    tasks[min_index].time = 0;
    for (int i = min_index+1; i < *num_tasks; i++) {
        tasks[i-1] = tasks[i];
    }
    *num_tasks -= 1;
}

int main() {
    srand(time(NULL)); // seed random number generator
    
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;
    
    for (int i = 0; i < 5; i++) {
        int id = i+1;
        int time = rand() % 10 + 1;
        printf("Scheduling task %d for %d seconds.\n", id, time);
        schedule_task(id, time, tasks, &num_tasks);
    }
    
    while (num_tasks > 0) {
        run_task(tasks, &num_tasks);
    }
    
    return 0;
}