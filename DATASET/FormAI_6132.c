//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10  //maximum number of tasks that can be scheduled
#define INTERVAL 1    //time interval for scheduling tasks (in seconds)

typedef struct {
    int id;           //task id
    int priority;     //priority of task
    int duration;     //time required to complete task (in seconds)
    int remaining;    //remaining time to complete task (in seconds)
    int status;       //status of task (0 = not started, 1 = in progress, 2 = complete)
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

void createTask(int priority, int duration) {
    if (taskCount < MAX_TASKS) {
        tasks[taskCount].id = taskCount;
        tasks[taskCount].priority = priority;
        tasks[taskCount].duration = duration;
        tasks[taskCount].remaining = duration;
        tasks[taskCount].status = 0;
        taskCount++;
    }
    else {
        printf("Task limit reached!\n");
    }
}

int getHighestPriorityTask() {
    int highestPriority = -1;
    int highestPriorityIndex = -1;
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].status == 0 && tasks[i].priority > highestPriority) {
            highestPriority = tasks[i].priority;
            highestPriorityIndex = i;
        }
    }
    return highestPriorityIndex;
}

void updateTask(int taskIndex) {
    tasks[taskIndex].remaining -= INTERVAL;
    if (tasks[taskIndex].remaining <= 0) {
        tasks[taskIndex].remaining = 0;
        tasks[taskIndex].status = 2;
        printf("Task %d complete!\n", tasks[taskIndex].id);
    }
    else {
        tasks[taskIndex].status = 1;
        printf("Task %d in progress...\n", tasks[taskIndex].id);
    }
}

int main() {
    srand(time(0));
    printf("Creating tasks...\n");
    createTask(1, rand() % 21 + 10);
    createTask(2, rand() % 21 + 10);
    createTask(3, rand() % 21 + 10);
    createTask(4, rand() % 21 + 10);
    createTask(5, rand() % 21 + 10);
    createTask(6, rand() % 21 + 10);

    int totalTime = 0;
    while (taskCount > 0) {
        int taskIndex = getHighestPriorityTask();
        if (taskIndex != -1) {
            updateTask(taskIndex);
        }
        totalTime += INTERVAL;
        if (totalTime % 5 == 0) {
            createTask(rand() % 5 + 1, rand() % 21 + 10);
        }
        printf("Total time elapsed: %d seconds\n", totalTime);
    }

    printf("All tasks complete!\n");
    return 0;
}