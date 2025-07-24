//FormAI DATASET v1.0 Category: Task Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>
#define MAX_TASKS 10

typedef struct Task {
    int id;
    char* name;
    int time;
} Task;

Task taskList[MAX_TASKS];
int taskCount;

void addTask(int id, char* name, int time) {
    if (taskCount >= MAX_TASKS) {
        printf("Task list full!\n");
        return;
    }
    Task newTask = {id, name, time};
    taskList[taskCount++] = newTask;
    printf("Task with id %d added.\n", id);
}

void deleteTask(int id) {
    int index;
    for (index = 0; index < taskCount; index++) {
        if (taskList[index].id == id) {
            break;
        }
    }
    if (index == taskCount) {
        printf("Task with id %d not found.\n", id);
        return;
    }
    for (int i = index; i < taskCount - 1; i++) {
        taskList[i] = taskList[i + 1];
    }
    taskCount--;
    printf("Task with id %d deleted.\n", id);
}

void executeTask(Task task) {
    printf("Executing task: %s\n", task.name);
    printf("Task took %d seconds to complete.\n", task.time);
}

void runScheduler() {
    printf("Running task scheduler...\n");
    while (taskCount > 0) {
        Task nextTask = taskList[0];
        for (int i = 1; i < taskCount; i++) {
            if (taskList[i].time < nextTask.time) {
                nextTask = taskList[i];
            }
        }
        executeTask(nextTask);
        deleteTask(nextTask.id);
    }
    printf("All tasks completed.\n");
}

int main() {
    taskCount = 0;
    addTask(1, "Task 1", 5);
    addTask(2, "Task 2", 3);
    addTask(3, "Task 3", 7);
    addTask(4, "Task 4", 1);
    runScheduler();
    return 0;
}