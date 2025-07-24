//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 3
#define CYBERPUNK_THEME "\033[38;5;214m"
#define RESET_COLOR "\033[0m"

typedef struct {
    int priority;
    char* name;
    void (*function)(void);
} Task;

int taskCount = 0;
Task taskList[MAX_TASKS];

void taskOne() {
    printf(CYBERPUNK_THEME "Task One is running\n" RESET_COLOR);
}

void taskTwo() {
    printf(CYBERPUNK_THEME "Task Two is running\n" RESET_COLOR);
}

void taskThree() {
    printf(CYBERPUNK_THEME "Task Three is running\n" RESET_COLOR);
}

void addTask(char* name, int priority, void (*function)(void)) {
    if (taskCount < MAX_TASKS) {
        Task task = {priority, name, function};
        taskList[taskCount] = task;
        taskCount++;
    }
}

void runTask(Task task) {
    printf(CYBERPUNK_THEME "Running task: %s (priority: %d)\n" RESET_COLOR, task.name, task.priority);
    task.function();
}

void taskScheduler() {
    if (taskCount > 0) {
        int i, j;
        for (i = 0; i < taskCount - 1; i++) {
            for (j = i + 1; j < taskCount; j++) {
                if (taskList[j].priority > taskList[i].priority) {
                    Task temp = taskList[j];
                    taskList[j] = taskList[i];
                    taskList[i] = temp;
                }
            }
        }
        runTask(taskList[0]);
    }
}

int main() {
    time_t t;
    srand((unsigned) time(&t));

    addTask("Task One", rand() % MAX_PRIORITY, taskOne);
    addTask("Task Two", rand() % MAX_PRIORITY, taskTwo);
    addTask("Task Three", rand() % MAX_PRIORITY, taskThree);

    while (1) {
        taskScheduler();
        sleep(1);
    }

    return 0;
}