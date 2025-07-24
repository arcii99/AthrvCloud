//FormAI DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of tasks
#define MAX_TASKS 10

// Define the task structure
typedef struct Task {
    char* name;
    int priority;
    void (*function)(void);
} Task;

// Define the task queue
Task taskQueue[MAX_TASKS];

// Define the current number of tasks in the queue
int currentTasks = 0;

// Add a task to the task queue
int addTask(char* name, int priority, void (*function)(void)) {
    // Check if the queue is not full
    if (currentTasks < MAX_TASKS) {
        // Create the new task
        Task newTask;
        newTask.name = name;
        newTask.priority = priority;
        newTask.function = function;

        // Add the new task to the queue
        taskQueue[currentTasks] = newTask;
        currentTasks++;

        // Return the success value
        return 0;
    } else {
        // Return the error value
        return -1;
    }
}

// Schedule the tasks in the task queue
void scheduleTasks() {
    // Loop through all the tasks in the queue
    for (int i = 0; i < currentTasks; i++) {
        // Get the highest priority task
        int highestPriorityIndex = i;
        for (int j = i+1; j < currentTasks; j++) {
            if (taskQueue[j].priority > taskQueue[highestPriorityIndex].priority) {
                highestPriorityIndex = j;
            }
        }

        // Execute the highest priority task
        taskQueue[highestPriorityIndex].function();

        // Remove the task from the queue
        for (int j = highestPriorityIndex; j < currentTasks-1; j++) {
            taskQueue[j] = taskQueue[j+1];
        }
        currentTasks--;
    }
}

// Define the task functions
void task1() { printf("Task 1 executed.\n"); }
void task2() { printf("Task 2 executed.\n"); }
void task3() { printf("Task 3 executed.\n"); }
void task4() { printf("Task 4 executed.\n"); }

int main() {
    // Add the tasks to the task queue
    addTask("Task 1", 2, task1);
    addTask("Task 2", 3, task2);
    addTask("Task 3", 1, task3);
    addTask("Task 4", 2, task4);

    // Schedule the tasks
    scheduleTasks();

    // Exit the program
    return 0;
}