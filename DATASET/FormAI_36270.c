//FormAI DATASET v1.0 Category: Task Scheduler ; Style: introspective
/* This example program demonstrates a task scheduler in C. 
 * It allows users to add tasks, specify their frequency and 
 * their function to execute. The program then dynamically 
 * schedules the tasks according to their frequency.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define MAX_TASKS 10           // Maximum number of tasks.
#define INTERVAL  1            // Interval between task executions (seconds).

// Structure to store task information.
struct task {
    int freq;                 // Frequency of task execution (seconds).
    int counter;              // Counter to track task execution.
    void (*func)(void);       // Pointer to function to execute.
};

struct task task_list[MAX_TASKS];
int num_tasks = 0;

// Function to add tasks to the task list.
void add_task(int freq, void (*func)(void)) {
    if (num_tasks == MAX_TASKS) {
        fprintf(stderr, "Maximum number of tasks reached.\n");
        exit(EXIT_FAILURE);
    }
    struct task new_task = {freq, 0, func};
    task_list[num_tasks++] = new_task;
}

// Function to execute a task.
void execute_task(int signum) {
    for (int i=0; i<num_tasks; i++) {
        struct task *current_task = &task_list[i];

        // If the frequency counter exceeds the frequency, execute the task.
        if (++current_task->counter >= current_task->freq) {
            current_task->counter = 0;
            (*current_task->func)();
        }
    }
}

// Function to print hello world.
void print_hello_world(void) {
    printf("Hello World!\n");
}

// Function to print the current time.
void print_current_time(void) {
    time_t t = time(NULL);
    char *current_time = ctime(&t);
    printf("The current time is %s", current_time);
}

int main(void) {
    // Register signal handler.
    if (signal(SIGALRM, execute_task) == SIG_ERR) {
        fprintf(stderr, "Failed to register SIGALRM signal handler.\n");
        exit(EXIT_FAILURE);
    }
   
    // Set interval.
    if (alarm(INTERVAL)) {
        fprintf(stderr, "An alarm has already been set. Exiting...\n");
        exit(EXIT_FAILURE);
    }
    
    // Add tasks.
    add_task(5, print_hello_world);
    add_task(10, print_current_time);

    // Loop indefinitely.
    while(1) {
        pause();
    }
    return 0;
}