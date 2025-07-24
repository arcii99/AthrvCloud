//FormAI DATASET v1.0 Category: Task Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_TASKS 100
#define MAX_TASK_NAME_LEN 20

typedef struct task
{
    char name[MAX_TASK_NAME_LEN];
    int delay_time;
    void (*func)(void);
} task_t;

task_t task_list[MAX_TASKS];
int task_count = 0;

pthread_t task_scheduler_thread;

void add_task(const char *name, int delay, void (*func)(void))
{
    if (task_count >= MAX_TASKS)
    {
        fprintf(stderr, "Unable to add more tasks.\n");
        return;
    }

    task_t new_task;
    new_task.delay_time = delay;
    new_task.func = func;
    strncpy(new_task.name, name, MAX_TASK_NAME_LEN);

    task_list[task_count++] = new_task;
}

void *task_scheduler(void *args)
{
    while (1)
    {
        for (int i = 0; i < task_count; i++)
        {
            if (task_list[i].delay_time < 1)
            {
                task_list[i].func();
                task_list[i].delay_time = -1;
            }
            else
            {
                task_list[i].delay_time--;
            }
        }

        // Remove executed tasks
        int i = 0;
        while (i < task_count)
        {
            if (task_list[i].delay_time == -1)
            {
                task_count--;

                for (int j = i; j < task_count; j++)
                {
                    task_list[j] = task_list[j + 1];
                }
            }
            else
            {
                i++;
            }
        }

        sleep(1);
    }

    return NULL;
}

void task1()
{
    printf("Task 1 executed!\n");
}

void task2()
{
    printf("Task 2 executed!\n");
}

void task3()
{
    printf("Task 3 executed!\n");
}

int main()
{
    add_task("Task 1", 3, task1);
    add_task("Task 2", 5, task2);
    add_task("Task 3", 10, task3);

    pthread_create(&task_scheduler_thread, NULL, task_scheduler, NULL);

    while (1)
    {
        // Do main program stuff
        printf("Main program is still running...\n");
        sleep(2);
    }

    return 0;
}