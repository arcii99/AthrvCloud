//FormAI DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

// Define a struct to hold information about tasks
typedef struct {
    char* name;
    int interval;
    void (*task_function)(void);
} Task;

// Array to hold all of the tasks
Task task_array[10];

// Function to add a task to the array
void add_task(char* name, int interval, void (*task_function)(void)) {
    // Find the next available slot in the array
    int i;
    for (i = 0; i < 10; i++) {
        if (task_array[i].name == NULL) {
            break;
        }
    }
    // Add the task to the array
    task_array[i].name = name;
    task_array[i].interval = interval;
    task_array[i].task_function = task_function;
}

// Function called when SIGALRM signal is received
void alarm_handler(int sig) {
    // Call each task that is due
    int i;
    for (i = 0; i < 10; i++) {
        if (task_array[i].name != NULL) {
            if (time(NULL) % task_array[i].interval == 0) {
                printf("%s is running\n", task_array[i].name);
                task_array[i].task_function();
            }
        }
    }
}

// Sample task functions
void task1() {
    printf("This is task1\n");
}

void task2() {
    printf("This is task2\n");
}

int main() {
    // Add some sample tasks to the array
    add_task("Task 1", 1, task1);
    add_task("Task 2", 2, task2);
    
    // Set up the alarm signal handler
    signal(SIGALRM, alarm_handler);
    
    // Set up the alarm to go off every second
    alarm(1);
    
    // Loop forever
    while (1) {
        sleep(1);
    }
    
    return 0;
}