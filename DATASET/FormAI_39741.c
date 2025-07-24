//FormAI DATASET v1.0 Category: Task Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// A function to call a task
void taskCall(void (*task)(void)) 
{
    (*task)();
}

// Task 1
void task1(void) 
{
    printf("Task 1 has been executed!\n");
}

// Task 2
void task2(void) 
{
    printf("Task 2 has been executed!\n");
}

// Task 3
void task3(void) 
{
    printf("Task 3 has been executed!\n");
}

// A task scheduler function
void taskScheduler(int taskNum, int duration, void (*tasks[])(void)) 
{
    printf("Running task scheduler...\n");

    for(int i = 0; i < taskNum; i++) 
    {
        taskCall(tasks[i]);
        sleep(duration);
    }
}

// Main function
int main() 
{
    // Declare an array of task functions
    void (*tasks[3])(void);

    tasks[0] = task1; // Assign task1 to the first element of the array
    tasks[1] = task2; // Assign task2 to the second element of the array
    tasks[2] = task3; // Assign task3 to the third element of the array

    // Call the task scheduler function
    taskScheduler(3, 2, tasks);

    return 0;
}