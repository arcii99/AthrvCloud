//FormAI DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define how many tasks we will have in our task table
#define NUM_TASKS 5

// Define the max number of ticks a task can have before being executed
#define MAX_TICKS 5

// Define a struct for each task
typedef struct {
    int id;         // ID of the task
    int ticks_left; // Ticks left before being executed
} task_t;

// Define our array of tasks
task_t task_table[NUM_TASKS];

// Define a function to randomly initialize task ticks
void init_task_ticks() {
    srand(time(NULL));     // Seed the random number generator
    int i;
    
    for (i = 0; i < NUM_TASKS; i++) {
        task_table[i].id = i+1;                     // Set the task ID
        task_table[i].ticks_left = rand() % MAX_TICKS + 1; // Set the number of ticks until execution
    }
}

// Define a function to decrement task ticks and execute if necessary
void execute_tasks() {
    int i;
    
    for (i = 0; i < NUM_TASKS; i++) {
        if (task_table[i].ticks_left > 0) {     // If there are still ticks left in the task, decrement and continue
            task_table[i].ticks_left--;
            continue;
        } else {
            printf("Task %d completed!\n", task_table[i].id);
            
            // Reset ticks and randomize a new amount for the task
            task_table[i].ticks_left = rand() % MAX_TICKS + 1;
        }
    }
}

int main() {
    init_task_ticks();
    
    while (1) {
        execute_tasks();
        
        // Wait for 1 second before executing tasks again
        sleep(1);
    }
    
    return 0;
}