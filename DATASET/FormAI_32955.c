//FormAI DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void task1();
void task2();
void task3();

void scheduler(int interval);
void startScheduler();

int main()
{
    startScheduler();

    return 0;
}

void task1()
{
    printf("Task 1 running...\n");
    sleep(2);
}

void task2()
{
    printf("Task 2 running...\n");
    sleep(4);
}

void task3()
{
    printf("Task 3 running...\n");
    sleep(3);
}

void scheduler(int interval)
{
    signal(SIGALRM, scheduler);

    task1();
    task2();
    task3();

    alarm(interval);
}

void startScheduler()
{
    int interval = 5;

    printf("Starting Task Scheduler...\n");
    printf("Interval set to %d seconds.\n", interval);

    scheduler(interval);
}