//FormAI DATASET v1.0 Category: Task Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Task structure that holds information about each task
typedef struct {
    int id; // unique task id
    int priority; // task priority, higher value means higher priority
    int time_to_execute; // time required to execute the task
} Task;

// Function to generate a random integer between min and max (inclusive)
int get_random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to print the details of a task
void print_task(Task task) {
    printf("Task ID: %d\n", task.id);
    printf("Priority: %d\n", task.priority);
    printf("Time to Execute: %d seconds\n", task.time_to_execute);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    int num_tasks = 5; // Total number of tasks to schedule
    int total_time = 0; // Total time required to execute all tasks
    
    Task tasks[num_tasks]; // Array to hold all tasks
    
    // Generate and populate the tasks array with random priority and execution time values
    printf("Generating Tasks...\n\n");
    for(int i = 0; i < num_tasks; i++) {
        tasks[i].id = i + 1;
        tasks[i].priority = get_random_int(1, 10);
        tasks[i].time_to_execute = get_random_int(1, 10);
        total_time += tasks[i].time_to_execute;
        printf("Task %d:\n", i + 1);
        print_task(tasks[i]);
        printf("\n");
    }

    // Sort the tasks array in descending order of priority
    for(int i = 0; i < num_tasks; i++) {
        for(int j = i + 1; j < num_tasks; j++) {
            if(tasks[i].priority < tasks[j].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
    
    printf("Scheduling Tasks...\n\n");
    
    int current_time = 0; // Current time in seconds
    int current_task_index = 0; // Index of the task currently being executed
    
    while(current_time < total_time) {
        
        // Check if current task is complete
        if(current_task_index < num_tasks && tasks[current_task_index].time_to_execute == 0) {
            printf("Task %d Completed!\n\n", tasks[current_task_index].id);
            current_task_index++;
        }
        
        // Find the highest priority task that has not started yet
        int next_task_index = current_task_index;
        for(int i = current_task_index; i < num_tasks; i++) {
            if(tasks[i].time_to_execute > 0 && tasks[i].priority > tasks[next_task_index].priority) {
                next_task_index = i;
            }
        }
        
        // Execute the next highest priority task for one second
        if(next_task_index < num_tasks) {
            printf("Task %d started!\n", tasks[next_task_index].id);
            tasks[next_task_index].time_to_execute--;
        }
        
        current_time++;
    }
    
    printf("All Tasks Completed!");
    
    return 0;
}