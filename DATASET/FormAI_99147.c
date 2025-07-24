//FormAI DATASET v1.0 Category: Task Scheduler ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

// A struct representing a task to be scheduled
typedef struct task
{
    int id;
    int interval; // Time interval between task execution (in seconds)
} Task;

int counter = 0;
Task task_array[3];

// Function to perform the task
void execute_task(int task_id)
{
    printf("Executing task %d\n", task_id);
}

// Signal handler function to handle SIGALRM signal
void handler(int signum)
{
    counter++;
    printf("Counter: %d\n", counter);
    
    // Check if it's time to execute a task
    for(int i = 0; i < 3; i++)
    {
        if(counter % task_array[i].interval == 0)
        {
            execute_task(task_array[i].id);
        }
    }
}

int main()
{
    // Create three tasks with different intervals
    task_array[0].id = 1;
    task_array[0].interval = 2;
    
    task_array[1].id = 2;
    task_array[1].interval = 5;
    
    task_array[2].id = 3;
    task_array[2].interval = 10;
    
    // Set up the signal handler for SIGALRM signal
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGALRM, &sa, NULL);
    
    // Set up the timer to trigger SIGALRM signal every second
    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);
    
    // Wait indefinitely for signals to be processed
    while(1)
    {
        sleep(1); // Sleep for 1 second
    }
    
    return 0; // End of program
}