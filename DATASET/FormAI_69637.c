//FormAI DATASET v1.0 Category: Task Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int priority;
    int delay;
    void (*func_ptr)(void);
} Task;

Task taskList[MAX_TASKS];
int currentTaskCount = 0;

void addTask(char* name, int priority, int delay, void (*func_ptr)(void)) {
    if (currentTaskCount >= MAX_TASKS) {
        printf("Task list is full.\n");
        return;
    }
    Task newTask;
    strncpy(newTask.name, name, MAX_NAME_LENGTH);
    newTask.priority = priority;
    newTask.delay = delay;
    newTask.func_ptr = func_ptr;
    taskList[currentTaskCount] = newTask;
    currentTaskCount++;
}

void executeTasks() {
    for (int i = 0; i < currentTaskCount; i++) {
        Task task = taskList[i];
        if (task.delay > 0) {
            task.delay--;
            continue;
        }
        printf("Executing task: %s\n", task.name);
        task.func_ptr();
    }
}

void task1() {
    printf("Task 1\n");
}

void task2() {
    printf("Task 2\n");
}

void task3() {
    printf("Task 3\n");
}

int main() {
    addTask("Task 1", 1, 5, &task1);
    addTask("Task 2", 2, 0, &task2);
    addTask("Task 3", 3, 2, &task3);
    executeTasks();
    return 0;
}