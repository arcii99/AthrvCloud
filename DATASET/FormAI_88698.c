//FormAI DATASET v1.0 Category: Task Scheduler ; Style: accurate
/* C Task Scheduler Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdbool.h>

// Task Struct
typedef struct Task {
    int id; // unique task ID
    int priority; // 0 for high priority and 1 for low priority
    char name[50]; // name of the task
    double time; // time interval in milliseconds
    time_t last_executed; // last execution time
} Task;

// Global Variables
Task task_list[50]; // list of all tasks
int task_count = 0;  // number of tasks in the list
bool should_exit = false; // flag for program exit

// Function to add a new task
void add_task(Task t) {
    task_list[task_count] = t;
    task_count++;
}

// Handler function for signals
void sig_handler(int sig) {
    switch(sig) {
        case SIGINT:
            printf("Stopping the program...\n");
            should_exit = true;
            break;
        case SIGALRM:
            // find the next task to execute
            Task next_task;
            int next_task_index = -1;
            time_t current_time = time(NULL);
            for(int i=0; i<task_count; i++) {
                if((current_time - task_list[i].last_executed) >= task_list[i].time) {
                    if(next_task_index == -1 || task_list[i].priority < next_task.priority) {
                        next_task = task_list[i];
                        next_task_index = i;
                    }
                }
            }
            // execute the next task
            if(next_task_index != -1) {
                printf("Executing task %s...\n", next_task.name);
                task_list[next_task_index].last_executed = time(NULL);
            }
            break;
    }
}

int main() {
    // initialize signal handlers
    signal(SIGINT, sig_handler);
    signal(SIGALRM, sig_handler);

    // create some sample tasks and add them to the list
    Task t1 = {1, 0, "Task A", 5000, time(NULL)};
    Task t2 = {2, 1, "Task B", 2000, time(NULL)};
    Task t3 = {3, 0, "Task C", 3000, time(NULL)};
    add_task(t1);
    add_task(t2);
    add_task(t3);

    // start the scheduler
    printf("Starting the scheduler...\n");
    struct itimerval timer;
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 1000;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 1000;
    setitimer(ITIMER_REAL, &timer, NULL);

    // wait for signals to exit
    while(!should_exit);

    return 0;
}