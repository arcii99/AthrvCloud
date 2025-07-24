//FormAI DATASET v1.0 Category: Task Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void task1();
void task2();
void task3();
void schedule(char task_name[], int task_priority, int task_interval, void (*task_function)(), int task_iterations);

// The main function
int main()
{
    // Schedule the tasks
    schedule("Task 1", 1, 5, task1, 10);
    schedule("Task 2", 3, 10, task2, 5);
    schedule("Task 3", 2, 20, task3, 3);

    // Run the tasks
    while(1);
    return 0;
}

// Task 1 function
void task1()
{
    printf("Task 1 executed at %ld\n", time(NULL));
}

// Task 2 function
void task2()
{
    printf("Task 2 executed at %ld\n", time(NULL));
}

// Task 3 function
void task3()
{
    printf("Task 3 executed at %ld\n", time(NULL));
}

// Schedule function
void schedule(char task_name[], int task_priority, int task_interval, void (*task_function)(), int task_iterations)
{
    printf("Scheduling %s with priority %d, interval %d and %d iterations.\n", task_name, task_priority, task_interval, task_iterations);

    // Seed the random number generator
    srand(time(NULL));

    // Calculate the initial delay
    int initial_delay = rand() % task_interval;

    // Schedule the first execution of the task
    printf("%s will be executed in %d seconds.\n\n", task_name, initial_delay);
    sleep(initial_delay);
    task_function();

    // Schedule the remaining executions of the task
    for(int i = 1; i < task_iterations; i++)
    {
        int delay = task_interval + (rand() % 5) - 2;
        printf("%s will be executed in %d seconds.\n\n", task_name, delay);
        sleep(delay);
        task_function();
    }

    printf("%s completed all iterations.\n\n", task_name);
}