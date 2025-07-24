//FormAI DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define a task structure
typedef struct Task {
    int id;
    int priority; 
    int duration;
} Task;

// Function that generates a random task
Task generate_task(int id) {
    Task task;
    task.id = id;
    task.priority = rand() % 10;
    task.duration = rand() % 10 + 1;
    return task;
}

// Function that prints a task's details
void print_task(Task task) {
    printf("Task ID: %d\n", task.id);
    printf("Priority: %d\n", task.priority);
    printf("Duration: %d\n", task.duration);
    printf("--------------------\n");
}

int main() {
    // Initialize an array of tasks
    Task tasks[10];
    for (int i = 0; i < 10; i++) {
        tasks[i] = generate_task(i+1);
    }
    
    // Schedule the tasks based on priority
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (tasks[i].priority < tasks[j].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
    
    // Print the scheduled tasks
    printf("Scheduled Tasks:\n");
    for (int i = 0; i < 10; i++) {
        print_task(tasks[i]);
    }
    
    // Execute the tasks
    int time = 0;
    printf("Executing Tasks:\n");
    for (int i = 0; i < 10; i++) {
        printf("Executing Task %d...\n", tasks[i].id);
        time += tasks[i].duration;
        printf("Task %d Completed in %d seconds.\n", tasks[i].id, tasks[i].duration);
        printf("--------------------\n");
    }
    
    // Print the total execution time
    printf("Total Execution Time: %d seconds\n", time);
    
    return 0;
}