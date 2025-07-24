//FormAI DATASET v1.0 Category: Task Scheduler ; Style: distributed
// C Task Scheduler Example Program

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_THREADS 10

// Task struct which contains the task name and task duration
typedef struct Task {
    char name[50];
    int duration;
} Task;

// Global variables
Task taskList[MAX_TASKS];
int numTasks = 0;
pthread_t threads[MAX_THREADS];
int numThreads = 0;

// Function to add tasks to the task list
void addTask(char *name, int duration) {
    Task task;
    strcpy(task.name, name);
    task.duration = duration;
    taskList[numTasks++] = task;
}

// Function which is executed by the threads
void *executeTask(void *arg) {
    int i;
    while (1) {
        for (i = 0; i < numTasks; i++) {
            if (taskList[i].duration > 0) {
                printf("Task %s is executing on thread %ld for %d seconds\n",
                       taskList[i].name, pthread_self(), taskList[i].duration);
                sleep(taskList[i].duration);
                taskList[i].duration = 0;
            }
        }
    }
    pthread_exit(NULL);
}

// Function to start the task scheduler and create threads
void startTaskScheduler(int numThreads) {
    int i;
    for (i = 0; i < numThreads; i++) {
        pthread_create(&threads[i], NULL, executeTask, NULL);
    }
}

int main()
{
    // Add tasks to the task list
    addTask("Task 1", 4);
    addTask("Task 2", 5);
    addTask("Task 3", 3);
    addTask("Task 4", 6);

    // Start the task scheduler with 4 threads
    startTaskScheduler(4);

    // Wait for all threads to complete
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}