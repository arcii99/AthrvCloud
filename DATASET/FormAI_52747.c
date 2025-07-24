//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the maximum number of tasks that can be scheduled
#define MAX_TASKS 100

// Define the maximum time a task can take to complete
#define MAX_TASK_TIME 10

// Define the maximum interval between two consecutive tasks
#define MAX_INTERVAL_TIME 5

struct Task {
    int id;
    int time;
};

struct TaskScheduler {
    bool isValid;
    int numOfTasks;
    int taskInterval;
    struct Task tasks[MAX_TASKS];
};

// Function to generate a random number within a specified range
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to create a task scheduler with random tasks and interval time
struct TaskScheduler createTaskScheduler() {
    struct TaskScheduler taskScheduler;
    taskScheduler.isValid = true;
    taskScheduler.numOfTasks = getRandomNumber(1, MAX_TASKS);

    // Create random tasks
    for (int i = 0; i < taskScheduler.numOfTasks; i++) {
        taskScheduler.tasks[i].id = i + 1;
        taskScheduler.tasks[i].time = getRandomNumber(1, MAX_TASK_TIME);
    }

    // Set random interval time between tasks
    taskScheduler.taskInterval = getRandomNumber(1, MAX_INTERVAL_TIME);

    return taskScheduler;
}

// Function to display the task scheduler and its tasks
void printTaskScheduler(struct TaskScheduler *taskScheduler) {
    printf("Task Scheduler - Total Tasks: %d, Task Interval: %d seconds\n", taskScheduler->numOfTasks, taskScheduler->taskInterval);
    printf("Tasks:\n");

    for (int i = 0; i < taskScheduler->numOfTasks; i++) {
        printf("Task %d - Time Required: %d seconds\n", taskScheduler->tasks[i].id, taskScheduler->tasks[i].time);
    }
}

// Function to execute a task and return the time taken
int executeTask(struct Task *task) {
    printf("Executing Task %d...\n", task->id);
    return task->time;
}

// Function to execute all tasks in the task scheduler with the specified interval
void executeTasks(struct TaskScheduler *taskScheduler) {
    int totalTime = 0;
    time_t startTime = time(NULL);

    for (int i = 0; i < taskScheduler->numOfTasks; i++) {
        int timeTaken = executeTask(&taskScheduler->tasks[i]);
        totalTime += timeTaken;

        // Wait for task interval time before executing the next task
        if (i != taskScheduler->numOfTasks - 1) {
            printf("Waiting for %d seconds before executing next task...\n", taskScheduler->taskInterval);
            sleep(taskScheduler->taskInterval);
        }
    }

    time_t endTime = time(NULL);
    int totalTimeTaken = difftime(endTime, startTime);

    printf("All tasks completed! - Time Taken: %d seconds, Total Task Time: %d seconds\n", totalTimeTaken, totalTime);
}

// Main function to create and execute a task scheduler
int main() {
    srand(time(NULL));

    struct TaskScheduler taskScheduler = createTaskScheduler();

    if (taskScheduler.isValid) {
        printTaskScheduler(&taskScheduler);
        executeTasks(&taskScheduler);
    }
    else {
        printf("Error: Invalid Task Scheduler\n");
    }

    return 0;
}