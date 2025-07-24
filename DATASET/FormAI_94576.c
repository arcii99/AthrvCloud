//FormAI DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>

#define MAX_TASKS 10

// typedef for function pointer
typedef void (*FunctionPointer)();

// Task struct
typedef struct Task {
    int id;
    int priority;
    FunctionPointer function;
} Task;

// Counter for task IDs
static int taskIDCounter = 1;

// Task array to hold all tasks
static Task tasks[MAX_TASKS];

// Number of tasks in the array
static int numTasks = 0;

// Add task function
void addTask(int priority, FunctionPointer func) {
    // Check if there is space in the tasks array
    if (numTasks >= MAX_TASKS) {
        printf("Error: Cannot add task. Maximum number of tasks reached.\n");
        return;
    }
    
    // Create new task and add to array
    Task newTask;
    newTask.id = taskIDCounter;
    newTask.priority = priority;
    newTask.function = func;
    
    tasks[numTasks] = newTask;
    numTasks++;
    
    // Increment task ID counter
    taskIDCounter++;
}

// Remove task function
void removeTask(int id) {
    // Find the index of the task to remove
    int taskIndex = -1;
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == id) {
            taskIndex = i;
            break;
        }
    }
    
    // If the task was found, remove it from the array
    if (taskIndex >= 0) {
        for (int i = taskIndex; i < numTasks-1; i++) {
            tasks[i] = tasks[i+1];
        }
        numTasks--;
    }
}

// Run tasks function
void runTasks() {
    // Sort tasks in order of priority (highest to lowest)
    for (int i = 0; i < numTasks-1; i++) {
        for (int j = i+1; j < numTasks; j++) {
            if (tasks[j].priority > tasks[i].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
    
    // Run each task
    for (int i = 0; i < numTasks; i++) {
        tasks[i].function();
    }
}

// Test functions
void test1() {
    printf("Running task 1.\n");
}

void test2() {
    printf("Running task 2.\n");
}

void test3() {
    printf("Running task 3.\n");
}

int main() {
    // Add tasks
    addTask(3, &test1);
    addTask(1, &test2);
    addTask(2, &test3);
    
    // Remove task 2
    removeTask(2);
    
    // Run tasks
    runTasks();
    
    return 0;
}