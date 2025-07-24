//FormAI DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TIME 5

typedef struct {
    int id;
    int time;
    int priority;
} Task;

Task tasks[MAX_TASKS];

void generate_tasks() {
    srand(time(NULL));
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].id = i + 1;
        tasks[i].time = rand() % MAX_TIME + 1;
        tasks[i].priority = rand() % MAX_TASKS + 1;
    }
}

int compare_priority(const void *a, const void *b) {
    Task *task1 = (Task *)a;
    Task *task2 = (Task *)b;
    return task1->priority - task2->priority;
}

void sort_tasks_by_priority() {
    qsort(tasks, MAX_TASKS, sizeof(Task), compare_priority);
}

void execute_task(Task task) {
    printf("Executing task %d for %d seconds\n", task.id, task.time);
    sleep(task.time);
}

int main() {
    generate_tasks();
    sort_tasks_by_priority();

    printf("Task list:\n");
    for (int i = 0; i < MAX_TASKS; i++) {
        printf("Task %d: Time=%d, Priority=%d\n", tasks[i].id, tasks[i].time, tasks[i].priority);
    }

    printf("Executing tasks in order of priority...\n");
    for (int i = 0; i < MAX_TASKS; i++) {
        execute_task(tasks[i]);
    }

    return 0;
}