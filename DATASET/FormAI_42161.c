//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scientific
/*
Program Title: Unique Task Scheduler Implementation
Purpose: To demonstrate a unique task scheduler in C
Author: [Your Name]
Date: [Current Date]

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define constants
#define TASK_COUNT 3
#define INTERVAL 2

// Define the task structure
struct task {
    int id;
    char *name;
    int interval;
    int completed;
};

// Define the task list
struct task task_list[TASK_COUNT] = {
    {1, "Task1", 5, 0},
    {2, "Task2", 2, 0},
    {3, "Task3", 1, 0}
};

// Define the scheduler function
void *scheduler(void *args) {
    while(1) {
        for(int i=0; i<TASK_COUNT; i++) {
            if(task_list[i].completed == 0) {
                printf("Running task %d - %s\n", task_list[i].id, task_list[i].name);
                sleep(task_list[i].interval);
                task_list[i].completed = 1;
                printf("Task %d - %s is complete\n", task_list[i].id, task_list[i].name);
            }
        }
        // Reset the task list if all tasks have been completed
        int all_completed = 1;
        for(int i=0; i<TASK_COUNT; i++) {
            if(task_list[i].completed == 0) {
                all_completed = 0;
                break;
            }
        }
        if(all_completed) {
            printf("All tasks completed. Resetting...\n");
            for(int i=0; i<TASK_COUNT; i++) {
                task_list[i].completed = 0;
            }
        }
    }
}

// Define the main function
int main() {
    // Initialize the thread
    pthread_t t;
    int rc = pthread_create(&t, NULL, scheduler, NULL);
    if(rc) {
        printf("ERROR: return code from pthread_create() is %d\n", rc);
        exit(1);
    }

    // Wait for the thread to finish
    pthread_join(t, NULL);

    // Exit the program
    return 0;
}