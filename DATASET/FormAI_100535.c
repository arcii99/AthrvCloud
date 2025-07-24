//FormAI DATASET v1.0 Category: Task Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// define the total number of tasks
#define NUM_TASKS 5

// an array to hold task details
struct task {
    int time;    // time required to complete the task
    char *name;  // name of the task
};

// an array of tasks to be executed
struct task tasks[NUM_TASKS] = {
    {3, "Task 1"},
    {5, "Task 2"},
    {2, "Task 3"},
    {4, "Task 4"},
    {1, "Task 5"}
};

// a function to execute the task
void execute_task(int task_index) {
    printf("\nExecuting task: %s\n", tasks[task_index].name);
    usleep(tasks[task_index].time * 1000000);  // sleep for time required to complete the task
    printf("Task %s completed.\n", tasks[task_index].name);
}

// main function
int main() {
    int i, j, pid, status;

    // execute tasks one by one
    for (i = 0; i < NUM_TASKS; i++) {
        // fork a child process to execute the task
        pid = fork(); 
        
        if (pid == 0) {
            // child process executes the task
            execute_task(i);
            exit(0);
        }
    }

    // wait for child processes to complete
    for (j = 0; j < NUM_TASKS; j++) {
        wait(&status);
    }

    return 0;
}