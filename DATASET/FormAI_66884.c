//FormAI DATASET v1.0 Category: Task Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define INTERVAL 1
#define TASKS_NUM 3

// task function prototypes
void task1();
void task2();
void task3();

// function pointer for tasks
void (*task_functions[])() =
{
    &task1,
    &task2,
    &task3
};

// task execution flags
volatile int task1_flag = 0;
volatile int task2_flag = 0;
volatile int task3_flag = 0;

// signal handler for SIGALRM
void signal_handler(int signal)
{
    switch (signal)
    {
        case SIGALRM:
            task1_flag = 1;
            task2_flag = 1;
            task3_flag = 1;
            break;
        default:
            break;
    }
}

// timer initialization
void set_timer()
{
    struct itimerval timer;
    timer.it_value.tv_sec = INTERVAL;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = INTERVAL;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);
}

// task 1
void task1()
{
    printf("Task 1 running...\n");
    // do some work here...
    sleep(2);
    printf("Task 1 completed.\n");
}

// task 2
void task2()
{
    printf("Task 2 running...\n");
    // do some work here...
    sleep(3);
    printf("Task 2 completed.\n");
}

// task 3
void task3()
{
    printf("Task 3 running...\n");
    // do some work here...
    sleep(1);
    printf("Task 3 completed.\n");
}

int main()
{
    struct sigaction sig_act;
    sig_act.sa_handler = signal_handler;
    sigemptyset(&sig_act.sa_mask);
    sig_act.sa_flags = 0;
    sigaction(SIGALRM, &sig_act, NULL);

    set_timer();
    
    while (1)
    {
        if (task1_flag)
        {
            task_functions[0]();
            task1_flag = 0;
        }
        else if (task2_flag)
        {
            task_functions[1]();
            task2_flag = 0;
        }
        else if (task3_flag)
        {
            task_functions[2]();
            task3_flag = 0;
        }
    }

    return 0;
}