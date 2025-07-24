//FormAI DATASET v1.0 Category: Task Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    void (*function)();
    int interval;
} Task;

Task taskList[MAX_TASKS];
int numTasks = 0;

pthread_mutex_t mutex;

void addTask(char* name, int interval, void (*function)()) {
    pthread_mutex_lock(&mutex);
    if (numTasks >= MAX_TASKS) {
        printf("Error: task list is full\n");
        pthread_mutex_unlock(&mutex);
        return;
    }
    Task task = { .interval=interval, .function=function };
    strncpy(task.name, name, MAX_NAME_LENGTH-1);
    taskList[numTasks++] = task;
    pthread_mutex_unlock(&mutex);
}

void removeTask(char* name) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < numTasks; i++) {
        if (strcmp(name, taskList[i].name) == 0) {
            for (int j = i; j < numTasks - 1; j++) {
                taskList[j] = taskList[j+1];
            }
            numTasks--;
            pthread_mutex_unlock(&mutex);
            return;
        }
    }
    printf("Error: task '%s' not found\n", name);
    pthread_mutex_unlock(&mutex);
}

void* runTasks(void* arg) {
    int* interval = (int*) arg;
    while (true) {
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < numTasks; i++) {
            if (*interval % taskList[i].interval == 0) {
                printf("Running task '%s'\n", taskList[i].name);
                taskList[i].function();
            }
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
        (*interval)++;
    }
}

void task1() {
    printf("Task 1 running\n");
}

void task2() {
    printf("Task 2 running\n");
}

int main() {
    pthread_t threadIds[MAX_TASKS];
    pthread_mutex_init(&mutex, NULL);

    addTask("task1", 2, &task1);
    addTask("task2", 5, &task2);

    int interval = 0;
    pthread_create(&threadIds[0], NULL, &runTasks, (void*) &interval);
    pthread_create(&threadIds[1], NULL, &runTasks, (void*) &interval);

    pthread_join(threadIds[0], NULL);
    pthread_join(threadIds[1], NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}