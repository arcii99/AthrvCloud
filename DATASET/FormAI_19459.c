//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define structure for task
struct Task {
    int task_id;
    int priority;
    int execution_time;
};

// Define function to print task details
void print_task(struct Task task) {
    printf("Task ID: %d\n", task.task_id);
    printf("Priority: %d\n", task.priority);
    printf("Execution Time: %d\n", task.execution_time);
}

// Define function to swap two tasks
void swap(struct Task* task1, struct Task* task2) {
    struct Task temp = *task1;
    *task1 = *task2;
    *task2 = temp;
}

// Define function to perform bubble sort on tasks based on priority
void sort_tasks(struct Task tasks[], int num_tasks) {
    for (int i = 0; i < num_tasks - 1; i++) {
        for (int j = 0; j < num_tasks - i - 1; j++) {
            if (tasks[j].priority < tasks[j + 1].priority) {
                swap(&tasks[j], &tasks[j + 1]);
            }
        }
    }
}

// Define function to execute a task
void execute_task(struct Task task, int current_time) {
    printf("Executing Task %d at time %d\n", task.task_id, current_time);
    current_time += task.execution_time;
}

int main() {
    srand((unsigned) time(NULL)); // Seed for random number generator

    int num_tasks = 5; // Number of tasks to be scheduled
    struct Task tasks[num_tasks]; // Array to store tasks

    // Generate random tasks
    for (int i = 0; i < num_tasks; i++) {
        tasks[i].task_id = i + 1;
        tasks[i].priority = rand() % 10 + 1;
        tasks[i].execution_time = rand() % 5 + 1;
        print_task(tasks[i]);
        printf("\n");
    }

    // Sort tasks based on priority
    sort_tasks(tasks, num_tasks);

    // Execute tasks in order of priority
    int current_time = 0;
    for (int i = 0; i < num_tasks; i++) {
        execute_task(tasks[i], current_time);
        current_time += 1; // Add some processing time before executing next task
    }

    return 0;
}