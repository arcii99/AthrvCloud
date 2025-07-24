//FormAI DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    int pid;
    char* name;
    int interval;
    int executed;
    int total_executions;
} Task;

Task task_list[MAX_TASKS];
int num_tasks = 0;

void add_task(int pid, char* name, int interval) {
    task_list[num_tasks].pid = pid;
    task_list[num_tasks].name = name;
    task_list[num_tasks].interval = interval;
    task_list[num_tasks].executed = 0;
    task_list[num_tasks].total_executions = 0;
    num_tasks++;
}

void execute_task(Task* task) {
    task->executed++;
    task->total_executions++;
    printf("Executing task '%s' (pid: %d)...\n", task->name, task->pid);
    // TODO: Add task logic here
}

void handle_signal(int signal) {
    if (signal == SIGALRM) {
        for (int i = 0; i < num_tasks; i++) {
            Task* task = &task_list[i];
            if (task->interval != 0 && task->executed == task->interval) {
                execute_task(task);
                task->executed = 0;
            }
        }
    }
}

void start_scheduler() {
    signal(SIGALRM, handle_signal);
    while (1) {
        alarm(1);
        pause();
    }
}

int main() {
    // Add tasks to the scheduler
    add_task(getpid(), "Task 1", 1);
    add_task(getpid(), "Task 2", 2);
    add_task(getpid(), "Task 3", 3);

    // Start the scheduler
    start_scheduler();

    return 0;
}