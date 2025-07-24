//FormAI DATASET v1.0 Category: Task Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variable to keep track of number of tasks
int num_tasks = 0;

// Struct for each task
typedef struct task {
    int priority;
    char* name;
    void (*function)();
    int time_left;
} Task;

// Array of tasks
Task tasks[10];

// Adding a task to the scheduler
void add_task(int priority, char* name, void (*function)(), int time) {
    // Check if there is space for the task
    if (num_tasks == 10) {
        printf("Oops, the task scheduler is full! Try again later.\n");
        return;
    }

    // Create new task
    Task new_task;
    new_task.priority = priority;
    new_task.name = name;
    new_task.function = function;
    new_task.time_left = time;

    // Find correct position to insert task
    int i;
    for (i = 0; i < num_tasks; i++) {
        if (tasks[i].priority < priority) {
            // Shift tasks to right to make space for new task
            int j;
            for (j = num_tasks; j > i; j--) {
                tasks[j] = tasks[j - 1];
            }
            break;
        }
    }

    // Add new task to array
    tasks[i] = new_task;
    num_tasks++;
}

// Running the task scheduler
void run_scheduler() {
    while (num_tasks > 0) {
        // Get current time
        time_t current_time;
        time(&current_time);
      
        // Pick random task to run
        int task_index = rand() % num_tasks;
        Task current_task = tasks[task_index];
      
        // Check if task has any time left
        if (current_task.time_left > 0) {
            // Execute task
            printf("Running task '%s'\n", current_task.name);
            current_task.function();
            current_task.time_left--;
          
            // If task is done, remove it from list
            if (current_task.time_left == 0) {
                printf("Task '%s' done!\n", current_task.name);
              
                // Shift tasks to left to fill gap
                int i;
                for (i = task_index; i < num_tasks - 1; i++) {
                    tasks[i] = tasks[i + 1];
                }
                num_tasks--;
            }
        }
        else {
            // Task has already finished, remove it from list
            printf("Task '%s' is already done!\n", current_task.name);
          
            // Shift tasks to left to fill gap
            int i;
            for (i = task_index; i < num_tasks - 1; i++) {
                tasks[i] = tasks[i + 1];
            }
            num_tasks--;
        }

        // Sleep for a random amount of time
        int sleep_time = rand() % 5 + 1;
        printf("Sleeping for %d seconds...\n", sleep_time);
        sleep(sleep_time);
    }
  
    printf("All tasks completed! Yay!\n");
}

// Example task functions
void task1() {
    printf("Task 1 running...\n");
}
void task2() {
    printf("Task 2 running...\n");
}
void task3() {
    printf("Task 3 running...\n");
}
void task4() {
    printf("Task 4 running...\n");
}
void task5() {
    printf("Task 5 running...\n");
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Add tasks to scheduler
    add_task(1, "Task 1", task1, 5);
    add_task(3, "Task 2", task2, 3);
    add_task(2, "Task 3", task3, 4);
    add_task(4, "Task 4", task4, 2);
    add_task(5, "Task 5", task5, 1);

    // Run scheduler
    run_scheduler();

    return 0;
}