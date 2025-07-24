//FormAI DATASET v1.0 Category: Task Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define tasks that will run on the scheduler
void task1(void)
{
    printf("Task 1 running[Priority = 1]\n");
    sleep(1);
}
void task2(void)
{
    printf("Task 2 running[Priority = 2]\n");
    sleep(1);
}
void task3(void)
{
    printf("Task 3 running[Priority = 3]\n");
    sleep(1);
}
void task4(void)
{
    printf("Task 4 running[Priority = 4]\n");
    sleep(1);
}

int main()
{
    // Define the tasks and their priorities
    void (*tasks[4])() = {task1, task2, task3, task4};
    int priorities[4] = {1, 2, 3, 4};

    // Set up the scheduler
    int i, j, k;
    for (i = 0; i < 4; i++) // Selection sort on priorities
    {
        int max_idx = i;
        for (j = i+1; j < 4; j++)
        {
            if (priorities[j] > priorities[max_idx])
            {
                max_idx = j;
            }
        }
        int temp = priorities[i];
        priorities[i] = priorities[max_idx];
        priorities[max_idx] = temp;

        void (*temp_task)() = tasks[i];
        tasks[i] = tasks[max_idx];
        tasks[max_idx] = temp_task;
    }

    // Run the tasks based on their priority
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (priorities[j] == (i+1))
            {
                tasks[j]();
            }
        }
    }

    // End of program
    printf("All tasks complete\n");
    return 0;
}