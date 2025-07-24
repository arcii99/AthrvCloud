//FormAI DATASET v1.0 Category: Task Scheduler ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Task Struct */
typedef struct task{
    int id;
    int priority;
    int execution_time;
    int remaining_time;
} task_t;

/* Function to print task details */
void display_task(task_t task) {
    printf("Task %d: Priority = %d | Execution Time = %d | Remaining Time = %d\n",
        task.id, task.priority, task.execution_time, task.remaining_time);
}

/* Function to generate a task with random values */
task_t generate_task(int id) {
    task_t new_task;
    new_task.id = id;
    new_task.priority = rand() % 10 + 1; // Random priority between 1 and 10
    new_task.execution_time = rand() % 10 + 1; // Random execution time between 1 and 10
    new_task.remaining_time = new_task.execution_time; // Initialize remaining time to execution time
    return new_task;
}

/* Main function */
int main() {
    srand(time(NULL)); // Seed the random number generator

    const int num_tasks = 5; // Number of tasks to generate
    task_t tasks[num_tasks]; // Array of tasks
    int total_execution_time = 0; // Total execution time of all tasks

    printf("Generating tasks...\n");
    for(int i=0; i<num_tasks; i++) {
        tasks[i] = generate_task(i+1); // Generate a task with ID = i+1
        total_execution_time += tasks[i].execution_time; // Add execution time to total
        display_task(tasks[i]); // Display task details
    }
    printf("Total Execution Time = %d\n", total_execution_time);

    printf("Scheduling tasks...\n");
    int current_time = 0; // Current time
    while(total_execution_time > 0) {
        task_t * highest_priority_task = NULL;
        int highest_priority = -1;

        for(int i=0; i<num_tasks; i++) {
            if(tasks[i].remaining_time > 0 && tasks[i].priority > highest_priority) { // Check if task is not done and has highest priority
                highest_priority_task = &tasks[i];
                highest_priority = tasks[i].priority;
            }
        }

        if(highest_priority_task != NULL) { // Execute task with highest priority
            printf("Executing Task %d at Time %d\n", highest_priority_task->id, current_time);
            highest_priority_task->remaining_time--;
            total_execution_time--;
        } else { // No tasks with remaining time and high priority
            printf("Skipping Time %d\n", current_time);
        }

        current_time++;
    }

    printf("All tasks completed!\n");

    return 0;
}