//FormAI DATASET v1.0 Category: Task Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the maximum number of tasks that can be scheduled
#define MAX_TASKS 10

// Define a structure to hold information about each task
typedef struct {
    char* name;
    int priority;
    time_t start_time;
    int duration;
} Task;

// Define an array to hold scheduled tasks
Task task_list[MAX_TASKS];

// Define the number of tasks currently scheduled
int num_tasks = 0;

// Function to add a task to the task list
void add_task() {
    // Check if the task list is already full
    if (num_tasks == MAX_TASKS) {
        printf("Error: Maximum number of tasks reached!\n");
        return;
    }

    // Allocate memory for the new task
    Task* new_task = malloc(sizeof(Task));

    // Get input from the user for the task properties
    printf("Enter task name: ");
    char* task_name = malloc(sizeof(char)*50);
    scanf("%s", task_name);
    new_task->name = task_name;

    printf("Enter task priority (1-10): ");
    scanf("%d", &(new_task->priority));

    printf("Enter task start time (in seconds since epoch): ");
    scanf("%ld", &(new_task->start_time));

    printf("Enter task duration (in seconds): ");
    scanf("%d", &(new_task->duration));

    // Add the new task to the task list and increment the task count
    task_list[num_tasks++] = *new_task;

    printf("Task '%s' has been added to the task list.\n", task_name);
}

// Function to remove a task from the task list
void remove_task() {
    // Check if there are any tasks to remove
    if (num_tasks == 0) {
        printf("Error: No tasks to remove!\n");
        return;
    }

    // Get input from the user for the task name to remove
    printf("Enter the name of the task to remove: ");
    char* task_name = malloc(sizeof(char)*50);
    scanf("%s", task_name);

    // Find the task with the matching name and remove it from the task list
    bool task_found = false;
    for (int i=0; i<num_tasks; i++) {
        if (strcmp(task_list[i].name, task_name) == 0) {
            // Free the memory used by the task's name string
            free(task_list[i].name);

            // Shift the remaining tasks left to fill the gap
            for (int j=i+1; j<num_tasks; j++) {
                task_list[j-1] = task_list[j];
            }

            // Decrement the task count
            num_tasks--;

            task_found = true;
            break;
        }
    }

    // Output a message indicating whether the task was found or not
    if (task_found) {
        printf("Task '%s' has been removed from the task list.\n", task_name);
    } else {
        printf("Error: Task '%s' not found!\n", task_name);
    }
}

// Function to print the list of scheduled tasks
void print_tasks() {
    // Check if there are any tasks to display
    if (num_tasks == 0) {
        printf("No tasks scheduled.\n");
        return;
    }

    // Output the header for the task list
    printf("%-20s%-10s%-25s%-10s\n", "Name", "Priority", "Start Time", "Duration");

    // Loop through the task list and output each task's information
    for (int i=0; i<num_tasks; i++) {
        printf("%-20s%-10d%-25s%-10d\n", task_list[i].name, task_list[i].priority,
               ctime(&(task_list[i].start_time)), task_list[i].duration);
    }
}

// Function to sort the task list by priority
void sort_tasks() {
    // Check if there are any tasks to sort
    if (num_tasks == 0) {
        printf("No tasks to sort.\n");
        return;
    }

    // Swap function for two tasks
    void swap(Task* a, Task* b) {
        Task temp = *a;
        *a = *b;
        *b = temp;
    }

    // Bubble sort on the task list based on priority, with higher priority tasks first
    for (int i=0; i<num_tasks-1; i++) {
        for (int j=0; j<num_tasks-i-1; j++) {
            if (task_list[j].priority < task_list[j+1].priority) {
                swap(&task_list[j], &task_list[j+1]);
            }
        }
    }

    printf("Task list has been sorted by priority.\n");
}

int main() {
    // Seed the random number generator for some random input later on
    srand(time(NULL));

    // Loop endlessly to accept user input for task scheduling
    while (true) {
        // Display the menu of available options
        printf("\n===== Task Scheduler =====\n");
        printf("1. Add a task\n");
        printf("2. Remove a task\n");
        printf("3. Print current tasks\n");
        printf("4. Sort tasks by priority\n");
        printf("5. Generate random tasks\n");
        printf("6. Quit\n");
        printf("Enter option: ");

        // Get input from the user for the menu option they want to choose
        int option;
        scanf("%d", &option);

        // Run the appropriate function based on the menu option chosen
        switch (option) {
            case 1:
                add_task();
                break;
            case 2:
                remove_task();
                break;
            case 3:
                print_tasks();
                break;
            case 4:
                sort_tasks();
                break;
            case 5:
                // Generate some random tasks for testing purposes
                printf("Generating random tasks...\n");
                char* names[] = {"Task A", "Task B", "Task C", "Task D", "Task E"};
                for (int i=0; i<5; i++) {
                    Task* new_task = malloc(sizeof(Task));
                    new_task->name = names[i];
                    new_task->priority = rand() % 10 + 1;
                    new_task->start_time = time(NULL) + rand() % 3600;
                    new_task->duration = rand() % 1800 + 300;
                    task_list[num_tasks++] = *new_task;
                }
                break;
            case 6:
                // Exit the program
                printf("Task scheduler exiting...\n");
                return 0;
            default:
                // Handle invalid menu options
                printf("Invalid menu option!\n");
                break;
        }
    }
}