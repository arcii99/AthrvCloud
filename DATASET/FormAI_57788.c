//FormAI DATASET v1.0 Category: Task Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_TASKS 10 // Maximum number of tasks that can be scheduled

// Define Task structure
typedef struct {
    int id; // Unique identifier for task
    int priority; // Priority of task
    int interval; // Time interval for task to be scheduled
    void (*function)(); // Pointer to function to be executed by task
} Task;

// Define Task Scheduler structure
typedef struct {
    Task tasks[MAX_TASKS]; // Array of tasks to be scheduled
    int numTasks; // Current number of tasks scheduled
    int timeElapsed; // Total time elapsed since scheduler started
    bool running; // Flag to indicate if scheduler is still running
} TaskScheduler;

// Define functions for Task Scheduler
void addTask(TaskScheduler *scheduler, int priority, int interval, void (*funcPtr)());
void removeTask(TaskScheduler *scheduler, int id);
void runScheduler(TaskScheduler *scheduler);

// Define sample task functions
void task1() {
    printf("Task 1 executed\n");
}

void task2() {
    printf("Task 2 executed\n");
}

void task3() {
    printf("Task 3 executed\n");
}

void task4() {
    printf("Task 4 executed\n");
}

int main() {
    // Create Task Scheduler and add sample tasks
    TaskScheduler scheduler;
    scheduler.numTasks = 0;
    scheduler.timeElapsed = 0;
    scheduler.running = true;
    
    addTask(&scheduler, 1, 3, &task1);
    addTask(&scheduler, 2, 5, &task2);
    addTask(&scheduler, 3, 2, &task3);
    addTask(&scheduler, 4, 6, &task4);
    
    // Run Task Scheduler
    runScheduler(&scheduler);
    
    return 0;
}

// Add Task function
void addTask(TaskScheduler *scheduler, int priority, int interval, void (*funcPtr)()) {
    if (scheduler->numTasks >= MAX_TASKS) {
        printf("Cannot add task: maximum limit reached\n");
        return;
    }
    Task newTask;
    newTask.id = scheduler->numTasks + 1;
    newTask.priority = priority;
    newTask.interval = interval;
    newTask.function = funcPtr;
    scheduler->tasks[scheduler->numTasks] = newTask;
    scheduler->numTasks++;
    printf("Task %d added successfully\n", newTask.id);
}

// Remove Task function
void removeTask(TaskScheduler *scheduler, int id) {
    int index = -1;
    for (int i = 0; i < scheduler->numTasks; i++) {
        if (scheduler->tasks[i].id == id) {
            index = i;
            break;
        }
    }
    if (index < 0) {
        printf("Cannot remove task: task with id %d does not exist\n", id);
        return;
    }
    for (int i = index + 1; i < scheduler->numTasks; i++) {
        scheduler->tasks[i - 1] = scheduler->tasks[i];
    }
    scheduler->numTasks--;
    printf("Task %d removed successfully\n", id);
}

// Run Task Scheduler function
void runScheduler(TaskScheduler *scheduler) {
    while (scheduler->running) {
        for (int i = 0; i < scheduler->numTasks; i++) {
            Task currentTask = scheduler->tasks[i];
            if (scheduler->timeElapsed % currentTask.interval == 0) {
                currentTask.function();
            }
        }
        scheduler->timeElapsed++;
        sleep(1); // Delay for 1 second between task executions
    }
}