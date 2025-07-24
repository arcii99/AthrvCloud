//FormAI DATASET v1.0 Category: Task Scheduler ; Style: brave
#include<stdio.h>
#define MAX_TASKS 10

// Structure representing a task
typedef struct {
    char name[20];  // Name of the task
    int period;     // Time period after which the task needs to be run
    int remaining;  // Remaining time until task needs to run
    void (*function)(); // Function pointer to the task function
} task_t;

// Array of tasks
task_t tasks[MAX_TASKS];

// Number of tasks in the array
int num_tasks = 0;

// Function to add a task to the array
void add_task(char name[], int period, void (*function)()) {
    if(num_tasks < MAX_TASKS) {
        task_t new_task;
        strcpy(new_task.name, name);
        new_task.period = period;
        new_task.remaining = period;
        new_task.function = function;
        tasks[num_tasks] = new_task;
        num_tasks++;
    }
}

// Function to run all tasks that are ready
void run_tasks() {
    for(int i = 0; i < num_tasks; i++) {
        if(tasks[i].remaining == 0) {
            tasks[i].function();
            tasks[i].remaining = tasks[i].period;
        }
        else {
            tasks[i].remaining--;
        }
    }
}

// Example tasks
void task1() {
    printf("Task 1 running...\n");
}

void task2() {
    printf("Task 2 running...\n");
}

// Main function to demonstrate the task scheduler
int main() {
    add_task("Task 1", 3, task1);
    add_task("Task 2", 5, task2);

    // Loop to simulate time passing
    for(int i = 0; i < 15; i++) {
        run_tasks();
    }

    return 0;
}