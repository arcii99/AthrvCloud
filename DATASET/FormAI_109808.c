//FormAI DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define TASK_COUNT 5
#define MAX_PRIORITY 10
#define MIN_PRIORITY 1

// Define task struct
typedef struct {
    int id;
    int priority;
    int duration;
} Task;

// Define global variables
Task taskList[TASK_COUNT];
int totalTime = 0;

// Define functions
void initializeTasks();
void sortTasksByPriority(Task tasks[], int left, int right);
void printTaskList();
void runScheduler();

int main() {
    initializeTasks();
    printTaskList();
    runScheduler();
    return 0;
}

// Initialize tasks with random priorities and durations
void initializeTasks() {
    srand(time(NULL));
    for (int i = 0; i < TASK_COUNT; i++) {
        taskList[i].id = i;
        taskList[i].priority = (rand() % (MAX_PRIORITY - MIN_PRIORITY + 1)) + MIN_PRIORITY;
        taskList[i].duration = (rand() % 5) + 1; // Max duration of 5 units
        totalTime += taskList[i].duration;
    }
}

// Sort tasks by priority in descending order
void sortTasksByPriority(Task tasks[], int left, int right) {
    if (left < right) {
        int pivot = tasks[left].priority;
        int i = left;
        int j = right;

        while (i <= j) {
            while (tasks[i].priority > pivot) {
                i++;
            }
            while (tasks[j].priority < pivot) {
                j--;
            }
            if (i <= j) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
                i++;
                j--;
            }
        }

        sortTasksByPriority(tasks, left, j);
        sortTasksByPriority(tasks, i, right);
    }
}

// Print task list
void printTaskList() {
    printf("Total time needed: %d\n", totalTime);
    printf("Tasks and priorities:\n");
    for (int i = 0; i < TASK_COUNT; i++) {
        printf("Task %d: Priority %d, Duration %d units\n", taskList[i].id, taskList[i].priority, taskList[i].duration);
    }
}

// Run task scheduler
void runScheduler() {
    int currentTime = 0;
    int currentTaskIndex = 0;

    while (currentTime < totalTime) {
        while (taskList[currentTaskIndex].duration <= 0) {
            currentTaskIndex++;
            if (currentTaskIndex >= TASK_COUNT) {
                break;
            }
        }
        if (currentTaskIndex >= TASK_COUNT) {
            break;
        }

        Task currentTask = taskList[currentTaskIndex];
        printf("Executing task %d, Priority %d, Duration %d units\n", currentTask.id, currentTask.priority, currentTask.duration);
        currentTime += currentTask.duration;
        currentTask.duration = 0;
        currentTaskIndex++;
    }

    printf("\nAll tasks completed in %d units of time.\n", currentTime);
}