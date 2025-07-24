//FormAI DATASET v1.0 Category: Task Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_TASKS 10

typedef struct Task 
{
    char name[50];
    int priority;
    int duration;
} Task;

void execute_task(Task task)
{
    printf("Executing task \"%s\" with priority %d and duration %d seconds...\n", task.name, task.priority, task.duration);
    sleep(task.duration);
    printf("Task \"%s\" finished executing.\n", task.name);
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Define an array of tasks
    Task tasks[MAX_TASKS] = {
        {"Clean the house", rand() % 10 + 1, rand() % 5 + 1},
        {"Do laundry", rand() % 10 + 1, rand() % 5 + 1},
        {"Go grocery shopping", rand() % 10 + 1, rand() % 5 + 1},
        {"Study for exam", rand() % 10 + 1, rand() % 5 + 1},
        {"Wash car", rand() % 10 + 1, rand() % 5 + 1},
        {"Pay bills", rand() % 10 + 1, rand() % 5 + 1},
        {"Walk dog", rand() % 10 + 1, rand() % 5 + 1},
        {"Make dinner", rand() % 10 + 1, rand() % 5 + 1},
        {"Exercise", rand() % 10 + 1, rand() % 5 + 1},
        {"Read book", rand() % 10 + 1, rand() % 5 + 1},
    };

    // Loop indefinitely
    while (true) 
    {
        // Loop through each task
        for (int i = 0; i < MAX_TASKS; i++) 
        {
            // Execute the task if its priority is high enough
            if (tasks[i].priority >= 5)
                execute_task(tasks[i]);
        }
    }

    return 0;
}