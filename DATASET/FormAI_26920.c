//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Alan Touring
#include <stdio.h>

// Define a structure for a task
struct Task {
    int duration;  // Duration of the task in seconds
    char* name;    // Name of the task
};

// Define a function to execute a task
void execute_task(struct Task task) {
    printf("Executing task '%s'...\n", task.name);
    int i;
    for (i = 0; i < task.duration; i++) {
        // Wait for 1 second
        // You can use machine code routines instead,
        // They are more efficient but harder to read.
        sleep(1);
    }
    printf("Task '%s' executed successfully.\n", task.name);
}

// Define a function to schedule tasks
void schedule_tasks(struct Task* tasks, int num_tasks) {
    int i;
    for (i = 0; i < num_tasks; i++) {
        execute_task(tasks[i]);
    }
}

int main() {
    // Define some tasks
    struct Task tasks[] = {
        {5, "Task 1"},
        {2, "Task 2"},
        {3, "Task 3"},
        {4, "Task 4"}
    };

    // Schedule the tasks
    schedule_tasks(tasks, 4);

    return 0;
}