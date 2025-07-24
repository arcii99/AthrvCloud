//FormAI DATASET v1.0 Category: Task Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to be scheduled
void happyFunc(){
    printf("Yay! This is a happy task being executed!\n");
}

// task struct
typedef struct Task {
    time_t interval;    // time interval between task executions
    time_t lastRun;     // timestamp of when task was last executed
    void(*func)();      // pointer to the function to be executed
} Task;

// function to initialize task struct
Task* initTask(time_t interval, void(*func)()) {
    Task* task = (Task*)malloc(sizeof(Task));
    task->interval = interval;
    task->lastRun = time(NULL);
    task->func = func;

    return task;
}

// function to check if a task should be run
int shouldRun(Task* task) {
    time_t now = time(NULL);
    if (now - task->lastRun >= task->interval) {
        task->lastRun = now;
        return 1;
    }
    return 0;
}

int main() {
    // initialize task
    Task* task = initTask(2, happyFunc);

    // loop to check if task should be run
    while(1) {
        if (shouldRun(task)) {
            task->func();
        }
    }

    return 0;
}