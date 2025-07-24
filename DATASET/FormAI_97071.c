//FormAI DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TASKS 5 // number of tasks
#define MAX_DELAY_IN_SECONDS 10 // maximum delay for a task

typedef struct {
    int id;
    int delay; // delay in seconds before executing the task
} Task;

void executeTask(Task* task) {
    printf("Executing task %d after %d seconds\n", task->id, task->delay);
}

void scheduleTask(Task* task) {
    time_t currentTime = time(NULL);
    time_t scheduledTime = currentTime + task->delay;
    while (currentTime < scheduledTime) {
        currentTime = time(NULL);
    }
    executeTask(task);
}

int main() {
    srand(time(NULL)); // initialize random number generator
    
    Task tasks[NUM_TASKS];
    for (int i = 0; i < NUM_TASKS; i++) {
        tasks[i].id = i;
        tasks[i].delay = rand() % MAX_DELAY_IN_SECONDS + 1;
        scheduleTask(&tasks[i]);
    }
    
    return 0;
}