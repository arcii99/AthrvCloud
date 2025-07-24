//FormAI DATASET v1.0 Category: Task Scheduler ; Style: statistical
/* Task Scheduler Example Program */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    char name[20];
    int priority;
    int time;
} Task;

Task taskList[MAX_TASKS]; // An array of tasks
int numTasks; // Number of tasks in the array

void initializeTasks();
void printTaskList();
void scheduleTasks();

int main() {
    initializeTasks();
    printf("Initial Task List:\n\n");
    printTaskList();
    printf("\n");
    scheduleTasks();
    printf("Scheduled Task List:\n\n");
    printTaskList();
    return 0;
}

/* Initializes the taskList array with random tasks */
void initializeTasks() {
    srand(time(0)); // Seed the random number generator
    numTasks = rand() % MAX_TASKS + 1; // Generate a random number between 1 and MAX_TASKS
    for (int i = 0; i < numTasks; i++) {
        sprintf(taskList[i].name, "Task %d", i+1);
        taskList[i].priority = rand() % 10 + 1; // Generate a random priority between 1 and 10
        taskList[i].time = rand() % 30 + 1; // Generate a random time between 1 and 30
    }
}

/* Prints the taskList array */
void printTaskList() {
    printf("Task\tPriority\tTime\n");
    printf("----\t--------\t----\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%s\t%d\t\t%d\n", taskList[i].name, taskList[i].priority, taskList[i].time);
    }
}

/* Schedules the tasks based on their priority and time */
void scheduleTasks() {
    Task tempTask;
    for (int i = 0; i < numTasks-1; i++) {
        for (int j = i+1; j < numTasks; j++) {
            if (taskList[i].priority < taskList[j].priority) { // If the priorities are different, swap the tasks
                tempTask = taskList[i];
                taskList[i] = taskList[j];
                taskList[j] = tempTask;
            }
            else if (taskList[i].priority == taskList[j].priority && taskList[i].time > taskList[j].time) { // If the priorities are the same, but the times are different, swap the tasks
                tempTask = taskList[i];
                taskList[i] = taskList[j];
                taskList[j] = tempTask;
            }
        }
    }
}