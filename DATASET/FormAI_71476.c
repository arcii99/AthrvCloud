//FormAI DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10 // maximum number of tasks that can be scheduled
#define RUNNING 1
#define STOPPED 0

typedef struct {
    int taskId;
    int priority;
    int (*taskFn)();
    int taskState;
} Task;

Task tasks[MAX_TASKS]; // array to hold all the scheduled tasks
int numTasks = 0; // number of tasks that are currently scheduled

// function to add a new task to the task scheduler
int addTask(int taskId, int priority, int (*taskFn)()) {
    if (numTasks >= MAX_TASKS) {
        printf("ERROR: Maximum number of tasks reached\n");
        return -1;
    }
    tasks[numTasks].taskId = taskId;
    tasks[numTasks].priority = priority;
    tasks[numTasks].taskFn = taskFn;
    tasks[numTasks].taskState = RUNNING;
    numTasks++;
    return 0;
}

// function to remove a task from the task scheduler
int removeTask(int taskId) {
    int i;
    for (i = 0; i < numTasks; i++) {
        if (tasks[i].taskId == taskId) {
            int j;
            for (j = i+1; j < numTasks; j++) {
                tasks[j-1] = tasks[j];
            }
            numTasks--;
            return 0;
        }
    }
    printf("ERROR: Task not found\n");
    return -1;
}

// function to start the task scheduler
int startScheduler() {
    while (1) {
        int i;
        int highestPriority = -1;
        int nextTask = -1;
        for (i = 0; i < numTasks; i++) {
            if (tasks[i].taskState == RUNNING && tasks[i].priority > highestPriority) {
                highestPriority = tasks[i].priority;
                nextTask = i;
            }
        }
        if (nextTask == -1) {
            printf("No tasks scheduled\n");
            return -1;
        }
        printf("Running task %d\n", tasks[nextTask].taskId);
        int retCode = tasks[nextTask].taskFn();
        if (retCode != 0) {
            printf("Task %d returned error code %d\n", tasks[nextTask].taskId, retCode);
            tasks[nextTask].taskState = STOPPED;
        }
    }
    return 0;
}

// some example task functions
int task1() {
    printf("Running task 1\n");
    return 0;
}

int task2() {
    printf("Running task 2\n");
    return 0;
}

int task3() {
    printf("Running task 3\n");
    return -1;
}

// main function to test the task scheduler
int main() {
    addTask(1, 1, task1);
    addTask(2, 2, task2);
    addTask(3, 3, task3);
    startScheduler();
    return 0;
}