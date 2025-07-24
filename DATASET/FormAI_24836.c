//FormAI DATASET v1.0 Category: Task Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Structure to hold task data
typedef struct {
    char name[50];
    int priority;
    int time;
} Task;

// Function to generate a random task
Task generateTask();

// Function to print task details
void printTask(Task task);

// Function to compare tasks based on priority
int compareTasks(const void* task1, const void* task2);

// Main function
int main(int argc, char const *argv[])
{
    // Seed the random number generator
    srand(time(NULL));

    // Create an array of tasks
    Task tasks[10];

    // Generate 10 random tasks
    for(int i=0; i<10; i++) {
        tasks[i] = generateTask();
    }

    // Print the unsorted task list
    printf("Unsorted Task List:\n");
    for(int i=0; i<10; i++) {
        printTask(tasks[i]);
    }

    // Sort the task list based on priority
    qsort(tasks, 10, sizeof(Task), compareTasks);

    // Print the sorted task list
    printf("Sorted Task List:\n");
    for(int i=0; i<10; i++) {
        printTask(tasks[i]);
    }

    return 0;
}

// Function to generate a random task
Task generateTask() {
    Task task;

    // Generate a random name
    char names[5][50] = {"Programming Assignment", "Meeting", "Lunch", "Phone Call", "Email"};
    int randIndex = rand() % 5;
    strcpy(task.name, names[randIndex]);

    // Generate a random priority and time
    task.priority = rand() % 10 + 1;
    task.time = rand() % 60 + 1;

    return task;
}

// Function to print task details
void printTask(Task task) {
    printf("Task Name: %s\n", task.name);
    printf("Priority: %d\n", task.priority);
    printf("Time: %d minutes\n\n", task.time);
}

// Function to compare tasks based on priority
int compareTasks(const void* task1, const void* task2) {
    Task t1 = *(Task*)task1;
    Task t2 = *(Task*)task2;

    if(t1.priority > t2.priority) {
        return -1;
    }
    else if(t1.priority < t2.priority) {
        return 1;
    }
    else {
        return 0;
    }
}