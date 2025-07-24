//FormAI DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_TASKS 100
#define MAX_NAME_LEN 255

// Define a Task struct
typedef struct Task {
    char name[MAX_NAME_LEN];
    int priority;
    time_t due;
    bool completed;
} Task;

// Define our Task Queue as an array of Tasks
Task taskQueue[MAX_TASKS];

// Maintain a count of the number of Tasks in our Task Queue
int numTasks = 0;

// Function to add a new task to the queue
void addTask(char* name, int priority, time_t due) {
    // Create a new Task
    Task newTask;
    strcpy(newTask.name, name);
    newTask.priority = priority;
    newTask.due = due;
    newTask.completed = false;

    // Add the new Task to the queue
    taskQueue[numTasks++] = newTask;
}

// Function to print all the tasks in our queue
void printTasks() {
    printf("Task List:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("- [%c] [%d] %s (Due: %s)\n", taskQueue[i].completed ? 'X' : ' ', taskQueue[i].priority, taskQueue[i].name, ctime(&taskQueue[i].due));
    }
}

int main() {

    // Add some example tasks
    addTask("Buy Groceries", 2, time(NULL) + 86400);
    addTask("Finish Project", 1, time(NULL) + 604800);
    addTask("Call Mom", 3, time(NULL) + 3600);

     printf("Welcome to the Task Scheduler\n\n");
    
    // Control loop
    while (true) {
        printf("Please choose an option:\n");
        printf("1. Add Task\n");
        printf("2. Complete Task\n");
        printf("3. Print Task List\n");
        printf("4. Exit Program\n");

        // Read user input
        int option;
        scanf("%d", &option);

        // Execute selected option
        switch (option) {
            case 1:
                // Add a new task
                char taskName[MAX_NAME_LEN];
                int priority;
                time_t due;
                printf("Enter Task Name: ");
                scanf("%s", taskName);
                printf("Enter Priority (1-5): ");
                scanf("%d", &priority);
                printf("Enter Due Date and Time (MM/DD/YYYY): ");
                struct tm dueDate;
                scanf("%d/%d/%d", &dueDate.tm_mon, &dueDate.tm_mday, &dueDate.tm_year);
                dueDate.tm_hour = 0;
                dueDate.tm_min = 0;
                dueDate.tm_sec = 0;
                due = mktime(&dueDate);
                addTask(taskName, priority, due);
                break;
            case 2:
                // Complete a task
                printf("Enter Task Number to Complete: ");
                int taskNum;
                scanf("%d", &taskNum);
                if (taskNum >= 0 && taskNum < numTasks) {
                    taskQueue[taskNum].completed = true;
                }
                break;
            case 3:
                // Print all tasks in the queue
                printTasks();
                break;
            case 4:
                // Exit program
                printf("Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                // Invalid option selected
                printf("Invalid option, please try again!\n");
                break;
        }
    }

    return 0;
}