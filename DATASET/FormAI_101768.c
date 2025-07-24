//FormAI DATASET v1.0 Category: Task Scheduler ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to simulate a task
void task(int id) {
    printf("Task %d completed!\n", id);
}

int main() {
    int task_ids[] = {1, 2, 3, 4, 5};    // List of task ids
    int num_tasks = sizeof(task_ids) / sizeof(int);    // Number of tasks
    int task_time = 2;    // Each task takes 2 seconds to complete
    int time_elapsed = 0;    // Time elapsed so far
    srand(time(NULL));    // Seed for random number generation
    
    printf("Welcome to the Task Scheduler!\n");
    
    // Iterate until all tasks are completed
    while(num_tasks > 0) {
        int random_task = rand() % num_tasks;    // Choose a random task from the list
        
        printf("Executing Task %d...\n", task_ids[random_task]);
        // Simulate task execution time
        for(int i=0; i<task_time; i++) {
            printf("Task in progress %d second(s)...\n", i+1);
            sleep(1);    // Pause for 1 second
            time_elapsed++;    // Increment the time elapsed
        }
        printf("\n");
        
        task(task_ids[random_task]);    // Call the task function
        // Remove the completed task from the list
        task_ids[random_task] = task_ids[num_tasks-1];
        num_tasks--;
    }
    
    printf("All tasks completed in %d seconds!\n", time_elapsed);
    printf("Thanks for using the Task Scheduler.\n");
    return 0;
}