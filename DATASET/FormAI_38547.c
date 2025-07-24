//FormAI DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TASKS 10
#define MAX_PRIORITY 5

typedef struct taskScheduler {
    int taskID;
    int priority;
    int deadline;
} Task;

void executeTask(Task* t) {
    // simulate task execution
    printf("Task %d with priority %d and deadline %d is being executed\n", t->taskID, t->priority, t->deadline);
    sleep(2);
    printf("Task %d with priority %d and deadline %d has been completed\n", t->taskID, t->priority, t->deadline);
}

void scheduleTask(Task* tasks, int numTasks) {
    for (int i = MAX_PRIORITY; i >= 0; i--) {
        for (int j = 0; j < numTasks; j++) {
            if (tasks[j].priority == i) {
                executeTask(&tasks[j]);
            }
        }
    }
}

int main() {
    srand(time(NULL)); // seed random number generator
    
    Task tasks[TASKS];
    
    // initialize tasks with random priorities and deadlines
    for (int i = 0; i < TASKS; i++) {
        tasks[i].taskID = i + 1;
        tasks[i].priority = rand() % (MAX_PRIORITY + 1);
        tasks[i].deadline = rand() % 10;
        
        printf("Task %d with priority %d and deadline %d has been added to the scheduler\n", tasks[i].taskID, tasks[i].priority, tasks[i].deadline);
    }
    
    // execute tasks in order of priority
    scheduleTask(tasks, TASKS);
    
    return 0;
}