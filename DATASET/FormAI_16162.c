//FormAI DATASET v1.0 Category: Task Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define TASKS_MAX   5 // Maximum number of tasks that can be scheduled
#define TASK_NAME   20 // Maximum length of the task names
#define INTERVAL    60 // The time interval at which tasks are executed (in seconds)

struct task {
    char name[TASK_NAME];
    int priority;
    int interval;
    time_t last_run;
    void *(*func)(void *);
};

struct task tasks[TASKS_MAX]; // Array of all the tasks that can be scheduled
int task_count = 0; // Current number of tasks scheduled

void *task_func1(void *arg)
{
    printf("Executing Task 1\n");
    return NULL;
}

void *task_func2(void *arg)
{
    printf("Executing Task 2\n");
    return NULL;
}

void *task_func3(void *arg)
{
    printf("Executing Task 3\n");
    return NULL;
}

void add_task(char* task_name, int priority, int interval, void *(*func)(void *))
{
    if (task_count >= TASKS_MAX) {
        printf("Cannot add more tasks\n");
        return;
    }

    strncpy(tasks[task_count].name, task_name, TASK_NAME);
    tasks[task_count].priority = priority;
    tasks[task_count].interval = interval;
    tasks[task_count].last_run = time(NULL);
    tasks[task_count].func = func;

    task_count++;
}

int should_run(struct task task)
{
    return (time(NULL) - task.last_run) >= task.interval;
}

void schedule_tasks()
{
    while (1) {
        for (int i = 0; i < task_count; ++i) {
            if (should_run(tasks[i])) {
                printf("Running Task: %s\n", tasks[i].name);
                pthread_t thread;
                pthread_create(&thread, NULL, tasks[i].func, NULL);
                tasks[i].last_run = time(NULL);
            }
        }
        sleep(INTERVAL);
    }
}

int main()
{
    add_task("Task 1", 1, 30, task_func1);
    add_task("Task 2", 2, 45, task_func2);
    add_task("Task 3", 3, 60, task_func3);

    schedule_tasks();

    return 0;
}