//FormAI DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRIORITY 5

// Task structure
typedef struct {
    int task_id;
    int priority;
    char* description;
} Task;

// Queue structure
typedef struct {
    int count;
    Task* tasks[100];
} Queue;

// Array of queues containing tasks of different priority levels
Queue task_queues[MAX_PRIORITY];

// Function declaration
void add_task();
void execute_task(Queue* queue);
void print_queues();

int main() {
    int choice;
    int quit = 0;

    // Initialize all task queues with count 0
    for (int i = 0; i < MAX_PRIORITY; i++) {
        task_queues[i].count = 0;
    }

    while (!quit) {
        printf("\n\nTask Scheduler Menu");
        printf("\n-------------------\n");
        printf("1. Add Task\n");
        printf("2. Execute Task\n");
        printf("3. Print Queues\n");
        printf("4. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                execute_task(&task_queues[0]);
                break;
            case 3:
                print_queues();
                break;
            case 4:
                quit = 1;
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add task to the appropriate priority queue
void add_task() {
    char* description = (char*)malloc(100 * sizeof(char));
    int priority;

    printf("\nEnter task description: ");
    scanf("%s", description);

    printf("Enter task priority (1-5): ");
    scanf("%d", &priority);

    if (priority < 1 || priority > MAX_PRIORITY) {
        printf("\nInvalid priority level.");
        free(description);
        return;
    }

    Task* new_task = (Task*)malloc(sizeof(Task));
    new_task->task_id = ++task_queues[priority - 1].count;
    new_task->priority = priority;
    new_task->description = description;
    task_queues[priority - 1].tasks[task_queues[priority - 1].count - 1] = new_task;

    printf("\nTask added successfully!\n");
}

// Function to execute the most recent task from the highest priority queue
void execute_task(Queue* queue) {
    int priority = MAX_PRIORITY;

    // Find the highest non-empty priority queue
    while (queue->count == 0 && priority > 1) {
        queue = &task_queues[--priority - 1];
    }

    // Execute the most recent task available in the queue
    if (queue->count > 0) {
        Task* task = queue->tasks[--queue->count];
        printf("\nTask ID: %d", task->task_id);
        printf("\nPriority: %d", task->priority);
        printf("\nDescription: %s\n", task->description);
        free(task->description);
        free(task);
    } else {
        printf("\nNo tasks available to execute.\n");
    }
}

// Function to print all queues and tasks in each queue
void print_queues() {
    printf("\nTask Queues\n");
    printf("-----------\n");

    for (int i = MAX_PRIORITY - 1; i >= 0; i--) {
        printf("\nPriority %d:", i + 1);

        if (task_queues[i].count == 0) {
            printf(" No tasks in queue.");
        } else {
            for (int j = 0; j < task_queues[i].count; j++) {
                printf("\nTask ID: %d | Description: %s", task_queues[i].tasks[j]->task_id, task_queues[i].tasks[j]->description);
            }
        }
    }
}