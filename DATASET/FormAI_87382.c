//FormAI DATASET v1.0 Category: Task Scheduler ; Style: synchronous
// C Task Scheduler Example Program

#include<stdio.h>
#include<stdlib.h>

typedef void (*TaskFunction)(void); // Define a TaskFunction typedef 

// A task with a function pointer and a priority
typedef struct Task {
    TaskFunction func;
    int priority;
} Task;

// Task queue with an array of tasks and a count of tasks
typedef struct TaskQueue {
    int count;
    Task tasks[100];
} TaskQueue;

// Add a task to the queue based on priority
void addTask(TaskQueue* queue, Task task) {
    int i = 0;
    for (i = 0; i < queue->count; i++) {
        if (task.priority > queue->tasks[i].priority) {
            break; // break the loop as soon as we find the correct location to insert
        }
    }
    
    // Move all the tasks after the new task's index, one index up
    for (int j = queue->count; j > i; j--) {
        queue->tasks[j] = queue->tasks[j - 1];
    }
    
    // Insert the new task at the correct position according to its priority
    queue->tasks[i] = task;
    
    // Increase the count of tasks in the queue
    queue->count++;
}

// Run all tasks in the queue in order of priority
void runTasks(TaskQueue* queue) {
    for (int i = 0; i < queue->count; i++) {
        queue->tasks[i].func(); // Call the task's function
    }
}

// Example tasks with different priorities
void task1() {
    printf("Task 1 is running.\n");
}

void task2() {
    printf("Task 2 is running.\n");
}

void task3() {
    printf("Task 3 is running.\n");
}

int main() {
    TaskQueue queue = {0};
    
    // Add tasks to the queue with different priorities
    addTask(&queue, (Task){&task1, 3});
    addTask(&queue, (Task){&task2, 1});
    addTask(&queue, (Task){&task3, 2});
    
    // Run all tasks in the queue based on their priority
    runTasks(&queue);
    
    return 0;
}