//FormAI DATASET v1.0 Category: Task Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a task struct
typedef struct Task {
    int task_id;
    int priority;
    char* description;
    int time_required;
} Task;

// Initialize the task scheduler
void schedule_task(Task *task, int num_tasks) {
    printf("Welcome to the funny task scheduler! Let's get started...\n\n");
    time_t t;
    srand((unsigned) time(&t)); // Set random seed

    // Loop through the tasks
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d: %s\n", task[i].task_id, task[i].description);
        printf("Priority: %d\n", task[i].priority);
        printf("Time required: %d seconds\n\n", task[i].time_required);

        // Randomize completion time
        int completion_time = rand() % task[i].time_required + 1;
        printf("Task %d is complete! It took %d seconds.\n\n", task[i].task_id, completion_time);
    }

    printf("All tasks complete! Thanks for using the funny task scheduler.\n");
}

int main() {
    // Define some tasks
    Task task_one = {1, 5, "Clean the toilet", 10};
    Task task_two = {2, 3, "Wash the dishes", 20};
    Task task_three = {3, 9, "Take out the trash", 5};
    Task task_four = {4, 1, "Order pizza", 30};

    // Add tasks to an array
    Task tasks[] = {task_one, task_two, task_three, task_four};

    // Calculate number of tasks
    int num_tasks = sizeof(tasks) / sizeof(tasks[0]);

    // Schedule the tasks
    schedule_task(tasks, num_tasks);

    return 0;
}