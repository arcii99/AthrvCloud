//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

// Function to be executed by the Task
void task_function(int task_id)
{
    printf("Executing Task %d\n", task_id);
}

// Callback function to handle the timer interrupt
void timer_callback(int signum)
{
    // Execute Task 1
    task_function(1);

    // Set timer for Task 2
    struct itimerval timer;
    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);
}

int main()
{
    // Set timer for Task 1
    struct itimerval timer;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    // Register the signal handler for the timer interrupt
    signal(SIGALRM, timer_callback);
    
    // Keep the main thread alive to continually schedule tasks
    while(1)
    {
        sleep(1);
    }

    return 0;
}