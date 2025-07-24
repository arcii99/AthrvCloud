//FormAI DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of tasks and the maximum execution time of each task
#define NUM_TASKS 10
#define MAX_EXEC_TIME 10

// Define the task structure
typedef struct {
    int id;
    int execution_time;
} Task;

// Define a function to generate a random task
Task generate_task(int id) {
    Task new_task;

    new_task.id = id;
    new_task.execution_time = rand() % MAX_EXEC_TIME + 1;

    return new_task;
}

int main() {
    // Create an array of tasks
    Task tasks[NUM_TASKS];

    // Seed the random number generator
    srand(time(NULL));

    // Generate the tasks
    for (int i = 0; i < NUM_TASKS; i++) {
        tasks[i] = generate_task(i);
    }

    // Sort the tasks by execution time
    for (int i = 0; i < NUM_TASKS - 1; i++) {
        for (int j = i + 1; j < NUM_TASKS; j++) {
            if (tasks[j].execution_time < tasks[i].execution_time) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    // Print out the task schedule
    printf("Task Schedule:\n");
    for (int i = 0; i < NUM_TASKS; i++) {
        printf("Task %d: Execution Time = %d\n", tasks[i].id, tasks[i].execution_time);
    }

    return 0;
}