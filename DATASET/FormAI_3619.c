//FormAI DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct task {
    char name[50];
    int priority;
    int time;
    int completed;
} Task;

// function to initialize a task
void initializeTask(Task *newTask, char name[], int priority, int time) {
    printf("Creating new task...\n");
    printf("Name: %s\n", name);
    printf("Priority: %d\n", priority);
    printf("Time: %d\n", time);
    newTask->completed = 0;
    printf("Task created successfully!\n");
}

// function to print information about a task
void printTask(Task task) {
    printf("Task Name: %s\n", task.name);
    printf("Priority: %d\n", task.priority);
    printf("Time: %d\n", task.time);
    if (task.completed == 1) {
        printf("Completed: Yes\n");
    } else {
        printf("Completed: No\n");
    }
}

// function to check if a task is completed
int isTaskCompleted(Task task) {
    return task.completed;
}

// global variables
Task taskList[10];
int numTasks = 0;

// function to add a new task to the task list
void addTask(char name[], int priority, int time) {
    Task newTask;
    initializeTask(&newTask, name, priority, time);
    taskList[numTasks] = newTask;
    numTasks++;
}

// function to print the task list
void printTaskList() {
    printf("Task List:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("Task %d:\n", i + 1);
        printTask(taskList[i]);
    }
}

// function to remove a task from the task list
void removeTask(int taskNum) {
    for (int i = taskNum - 1; i < numTasks - 1; i++) {
        taskList[i] = taskList[i + 1];
    }
    numTasks--;
}

// function to find the highest priority task
int findHighestPriorityTask() {
    int highestPriority = 0;
    int taskIndex = -1;
    for (int i = 0; i < numTasks; i++) {
        if (taskList[i].priority > highestPriority && isTaskCompleted(taskList[i]) == 0) {
            highestPriority = taskList[i].priority;
            taskIndex = i;
        }
    }
    return taskIndex;
}

// function to simulate running a task
void runTask(int taskNum) {
    printf("Task %d is running...\n", taskNum);
    taskList[taskNum - 1].completed = 1;
    printf("Task %d is now complete!\n", taskNum);
}

// function to simulate the task scheduler
void taskScheduler() {
    int taskNum;
    while (numTasks > 0) {
        taskNum = findHighestPriorityTask();
        if (taskNum != -1) {
            runTask(taskNum + 1);
            removeTask(taskNum + 1);
        } else {
            printf("No tasks left to run!\n");
            break;
        }
    }
}

int main() {
    addTask("Write report", 3, 5);
    addTask("Do laundry", 2, 3);
    addTask("Buy groceries", 1, 2);
    printTaskList();
    taskScheduler();
    return 0;
}