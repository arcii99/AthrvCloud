//FormAI DATASET v1.0 Category: Task Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TASKS 5
#define MAX_PRIORITY 3
#define MAX_RUNTIME 10

typedef struct Task {
    int priority;
    int runtime;
} Task;

void initializeTasks(Task tasks[]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_TASKS; i++) {
        tasks[i].priority = rand() % (MAX_PRIORITY + 1);
        tasks[i].runtime = rand() % MAX_RUNTIME + 1;
    }
}

void printTasks(Task tasks[]) {
    printf("Priority\tRuntime\n");
    for (int i = 0; i < NUM_TASKS; i++) {
        printf("%d\t\t%d\n", tasks[i].priority, tasks[i].runtime);
    }
}

void executeTask(Task task) {
    printf("Executing task...\n");
    for (int i = 0; i < task.runtime; i++) {
        // Do some work here
    }
    printf("Task complete.\n");
}

void scheduleTasks(Task tasks[]) {
    printf("Scheduling tasks...\n");
    for (int i = MAX_PRIORITY; i >= 0; i--) {
        for (int j = 0; j < NUM_TASKS; j++) {
            if (tasks[j].priority == i) {
                executeTask(tasks[j]);
            }
        }
    }
    printf("All tasks completed.\n");
}

int main() {
    Task tasks[NUM_TASKS];
    initializeTasks(tasks);
    printf("Initial Tasks:\n");
    printTasks(tasks);
    scheduleTasks(tasks);
    return 0;
}