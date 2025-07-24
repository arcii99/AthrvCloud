//FormAI DATASET v1.0 Category: Educational ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

/* Post-apocalyptic C program that allows users to manage and assign tasks */

// Struct representing a task
typedef struct {
    int id;
    char description[100];
    int priority;
    int completed;
} Task;

// Global array of Task objects
Task tasks[50];
int numTasks = 0;

// Function declarations
void displayMenu();
void addTask();
void viewAllTasks();
void selectTask();
void completeTask();
void deleteTask();

int main() {
    // Initialize tasks array
    for (int i = 0; i < 50; i++) {
        tasks[i].id = -1;
    }
    
    // Display menu options until user exits
    int input = -1;
    while (input != 6) {
        displayMenu();
        scanf("%d", &input);
    
        switch(input) {
            case 1:
                addTask();
                break;
            case 2:
                viewAllTasks();
                break;
            case 3:
                selectTask();
                break;
            case 4:
                completeTask();
                break;
            case 5:
                deleteTask();
                break;
            case 6:
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }
    
    return 0;
}

// Displays menu options to the user
void displayMenu() {
    printf("\nWelcome to Task Manager!\n");
    printf("1. Add task\n");
    printf("2. View all tasks\n");
    printf("3. Select task\n");
    printf("4. Mark task as complete\n");
    printf("5. Delete task\n");
    printf("6. Exit\n\n");
    printf("Enter your choice: ");
}

// Adds a new task to the tasks array
void addTask() {
    // Prompt user for task description and priority
    printf("\nEnter task description: ");
    scanf(" %[^\n]s", tasks[numTasks].description);
    printf("Enter task priority (1-10): ");
    scanf("%d", &tasks[numTasks].priority);
    
    // Set task ID and completed status
    tasks[numTasks].id = numTasks;
    tasks[numTasks].completed = 0;
    
    printf("Task successfully added!\n");
    numTasks++;
}

// Displays all tasks in the tasks array
void viewAllTasks() {
    if (numTasks == 0) {
        printf("No tasks available.\n");
        return;
    }
    
    printf("\nAll tasks:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%d. %s (Priority: %d, Completed: %s)\n", tasks[i].id, tasks[i].description, tasks[i].priority, tasks[i].completed ? "Yes" : "No");
    }
}

// Asks user to select a task and displays its details
void selectTask() {
    if (numTasks == 0) {
        printf("No tasks available.\n");
        return;
    }
    
    int taskId;
    printf("\nEnter task ID: ");
    scanf("%d", &taskId);
    
    // Find task in tasks array and display details
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            printf("\nTask details:\n");
            printf("Description: %s\n", tasks[i].description);
            printf("Priority: %d\n", tasks[i].priority);
            printf("Completed: %s\n", tasks[i].completed ? "Yes" : "No");
            return;
        }
    }
    
    printf("Task ID not found. Please try again.\n");
}

// Asks user to select a task and marks it as completed
void completeTask() {
    if (numTasks == 0) {
        printf("No tasks available.\n");
        return;
    }
    
    int taskId;
    printf("\nEnter task ID: ");
    scanf("%d", &taskId);
    
    // Find task in tasks array and mark as completed
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            if (tasks[i].completed) {
                printf("Task already completed.\n");
                return;
            } else {
                tasks[i].completed = 1;
                printf("Task marked as completed!\n");
                return;
            }
        }
    }
    
    printf("Task ID not found. Please try again.\n");
}

// Asks user to select a task and deletes it from the tasks array
void deleteTask() {
    if (numTasks == 0) {
        printf("No tasks available.\n");
        return;
    }
    
    int taskId;
    printf("\nEnter task ID: ");
    scanf("%d", &taskId);
    
    // Find task in tasks array and delete it
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            for (int j = i; j < numTasks - 1; j++) {
                tasks[j] = tasks[j+1];
            }
            numTasks--;
            printf("Task successfully deleted!\n");
            return;
        }
    }
    
    printf("Task ID not found. Please try again.\n");
}