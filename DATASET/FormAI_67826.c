//FormAI DATASET v1.0 Category: Task Scheduler ; Style: modular
#include<stdio.h>

//Module for scheduling tasks
void scheduleTask(int minutes, void (*task)(void))
{
    sleep(minutes * 60);  //Wait for the specified number of minutes
    printf("Task executing after %d minutes...\n", minutes);
    (*task)();  //Execute the task
}

//Sample tasks to be scheduled
void task1()
{
    printf("Executing Task 1...\n");
}

void task2()
{
    printf("Executing Task 2...\n");
}

int main()
{
    //Schedule Task 1 after 2 minutes
    scheduleTask(2, task1);

    //Schedule Task 2 after 5 minutes
    scheduleTask(5, task2);

    return 0;
}