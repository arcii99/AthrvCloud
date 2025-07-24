//FormAI DATASET v1.0 Category: Task Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    int priority;
    int task_id;
    double execution_time;
} Task;

int cmpfunc(const void * a, const void * b) {
    Task t1 = *(Task*)a;
    Task t2 = *(Task*)b;
    if (t1.priority < t2.priority) {
        return 1;
    } else if (t1.priority > t2.priority) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));
    Task task_list[10];
    int total_tasks = 10;
    double total_execution_time = 0.0;
    double average_execution_time;
    int i, j;
    for (i = 0; i < total_tasks; i++) {
        task_list[i].priority = rand() % 10;
        task_list[i].task_id = i+1;
        task_list[i].execution_time = (double)((rand() % 100) / 10.0);
        total_execution_time += task_list[i].execution_time;
    }
    qsort(task_list, total_tasks, sizeof(Task), cmpfunc);
    average_execution_time = total_execution_time / total_tasks;

    printf("Task Scheduler:\n");
    for (i = 0, j = 1; i < total_tasks; i++, j++) {
        printf("Task ID: %2d, Priority: %d, Execution Time: %3.1lf sec\n", task_list[i].task_id, task_list[i].priority, task_list[i].execution_time);
        printf("Task %2d started. \n", j);
        sleep((int)task_list[i].execution_time);
        printf("Task %2d completed. \n\n", j);
        if (task_list[i].execution_time > average_execution_time) {
            printf("WARNING: Task %2d took longer than average execution time. \n\n", j);
        }
    }
    printf("All tasks completed successfully! \n");
    return 0;
}