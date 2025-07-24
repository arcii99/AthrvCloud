//FormAI DATASET v1.0 Category: Task Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10 // maximum number of tasks that can be scheduled
#define MAX_PRIORITY 5 // maximum priority level, from 0 to MAX_PRIORITY-1
#define MAX_RUNTIME 10 // maximum runtime of a task, in seconds

typedef struct task {
    int id;
    int priority;
    int runtime;
} task_t;

void schedule_task(task_t *tasks, int num_tasks) {
    int i, j, min_idx;
    task_t temp;
    // sort tasks based on priority (ascending order)
    for (i = 0; i < num_tasks - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < num_tasks; j++) {
            if (tasks[j].priority < tasks[min_idx].priority) {
                min_idx = j;
            }
        }
        temp = tasks[i];
        tasks[i] = tasks[min_idx];
        tasks[min_idx] = temp;
    }
    // run tasks in priority order
    for (i = 0; i < num_tasks; i++) {
        printf("Running task %d with priority %d and runtime %d seconds.\n", tasks[i].id, tasks[i].priority, tasks[i].runtime);
        sleep(tasks[i].runtime); // simulate task runtime
    }
}

int main() {
    srand(time(NULL)); // seed random number generator
    int num_tasks = rand() % MAX_TASKS + 1; // generate random number of tasks
    task_t tasks[num_tasks]; // create array of task structs
    int i;
    // generate random tasks
    for (i = 0; i < num_tasks; i++) {
        tasks[i].id = i;
        tasks[i].priority = rand() % MAX_PRIORITY; // generate random priority level
        tasks[i].runtime = rand() % MAX_RUNTIME + 1; // generate random runtime (up to MAX_RUNTIME seconds)
    }
    printf("Generated %d tasks:\n", num_tasks);
    // print generated tasks
    for (i = 0; i < num_tasks; i++) {
        printf("Task %d: priority=%d, runtime=%d seconds.\n", tasks[i].id, tasks[i].priority, tasks[i].runtime);
    }
    // schedule tasks
    schedule_task(tasks, num_tasks);
    return 0;
}