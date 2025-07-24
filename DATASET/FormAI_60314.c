//FormAI DATASET v1.0 Category: Task Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 10 // Maximum number of tasks
#define MAX_TASK_NAME_LENGTH 20 // Maximum length of task name
#define MAX_TASK_EXECUTION_TIME 10 // Maximum execution time of task
#define MAX_TIME_DELAY 5 // Maximum delay before task execution

typedef struct task {
    char task_name[MAX_TASK_NAME_LENGTH];
    int execution_time;
    int has_executed;
} Task;

Task task_list[MAX_TASKS];
int num_tasks;

void schedule_task(int sig) {
    srand(time(NULL));
    int random_index = rand() % num_tasks;
    while (task_list[random_index].has_executed) {
        random_index = rand() % num_tasks;
    }
    printf("Executing task: %s\n", task_list[random_index].task_name);
    sleep(task_list[random_index].execution_time);
    printf("Task %s completed after %d seconds\n", task_list[random_index].task_name, task_list[random_index].execution_time);
    task_list[random_index].has_executed = 1;
}

int main() {
    num_tasks = 0;
    // Add tasks to the task list
    Task task1 = {"Task 1", 5, 0};
    task_list[num_tasks++] = task1;
    
    Task task2 = {"Task 2", 7, 0};
    task_list[num_tasks++] = task2;
    
    Task task3 = {"Task 3", 10, 0};
    task_list[num_tasks++] = task3;

    // Set up signal handler for alarm signal
    signal(SIGALRM, schedule_task);
    
    // Schedule tasks at random intervals
    while (1) {
        int delay_time = rand() % MAX_TIME_DELAY;
        sleep(delay_time);
        if (num_tasks > 0) {
            alarm(1);
            pause();
        } else {
            printf("No tasks remaining\n");
            exit(0);
        }
    }
    return 0;
}