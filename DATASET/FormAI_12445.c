//FormAI DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The number of maximum achievable tasks
#define MAX_TASKS 10

// Structure to hold task information
struct task {
    char name[20];
    int priority;
    int duration;
};

// Function to generate a random task
struct task generate_task() {
    struct task new_task;
    // Randomly assign a name
    int name_num = rand() % 5;
    switch (name_num) {
        case 0:
            strcpy(new_task.name, "Scavenging");
            break;
        case 1:
            strcpy(new_task.name, "Hunting");
            break;
        case 2:
            strcpy(new_task.name, "Gathering");
            break;
        case 3:
            strcpy(new_task.name, "Guard Duty");
            break;
        case 4:
            strcpy(new_task.name, "Building");
            break;
    }
    // Randomly assign a priority
    new_task.priority = rand() % 3;
    // Randomly assign a duration between 1-4 hours
    new_task.duration = rand() % 4 + 1;
    return new_task;
}

// Function to print a task
void print_task(struct task task1) {
    printf("%s [Priority: %d | Duration: %d hours]\n", task1.name, task1.priority, task1.duration);
}

// Function to swap two tasks in an array
void swap_tasks(struct task* task1, struct task* task2) {
    struct task temp = *task1;
    *task1 = *task2;
    *task2 = temp;
}

// Function to sort tasks by priority (highest first)
void sort_priority(struct task tasks[], int task_count) {
    int i, j;
    for (i = 0; i < task_count - 1; i++) {
        for (j = 0; j < task_count - i - 1; j++) {
            if (tasks[j].priority < tasks[j+1].priority) {
                swap_tasks(&tasks[j], &tasks[j+1]);
            }
        }
    }
}

int main() {
    // Seed random function
    srand(time(NULL));
    // Initiate task array
    struct task tasks[MAX_TASKS];
    int task_count = 0;
    // Generate random tasks and add to array
    while (task_count < MAX_TASKS) {
        tasks[task_count] = generate_task();
        task_count++;
    }
    // Sort tasks by priority
    sort_priority(tasks, task_count);
    // Execute tasks in order
    printf("Task Scheduler Algorithm\n");
    printf("========================\n");
    int i, total_duration = 0;
    for (i = 0; i < task_count; i++) {
        printf("Executing Task %d:\n", i+1);
        print_task(tasks[i]);
        total_duration += tasks[i].duration;
        printf("Total time elapsed: %d hours\n\n", total_duration);
    }
    printf("All tasks complete. Total time elapsed: %d hours.\n", total_duration);
    return 0;
}