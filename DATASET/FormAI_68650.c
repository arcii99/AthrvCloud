//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define TASKS_NUM 10
#define MAX_TASK_TIME 100
#define MAX_PRIORITY 10

typedef struct {
    int task_id;
    int task_time;
    int priority;
} task_t;

typedef struct {
    task_t* tasks;
    int num_tasks;
} task_list_t;

int compare_tasks(const void* p1, const void* p2) {
    task_t* task1 = (task_t*) p1;
    task_t* task2 = (task_t*) p2;
    if (task1->priority != task2->priority)
        return task2->priority - task1->priority; // Higher priority comes first
    else
        return task1->task_id - task2->task_id;   // Tasks with lower id come first
}

int main() {
    srand(42); // Seed the RNG

    // Create a list of tasks
    task_t tasks[TASKS_NUM];
    for (int i = 0; i < TASKS_NUM; i++) {
        tasks[i].task_id = i;
        tasks[i].task_time = rand() % MAX_TASK_TIME + 1; // Task time range: [1, MAX_TASK_TIME]
        tasks[i].priority = rand() % MAX_PRIORITY + 1;   // Priority range: [1, MAX_PRIORITY]
    }

    // Sort tasks in order of decreasing priority and increasing id
    qsort(tasks, TASKS_NUM, sizeof(task_t), compare_tasks);

    // Create a task list with the sorted tasks
    task_list_t task_list;
    task_list.tasks = tasks;
    task_list.num_tasks = TASKS_NUM;

    printf("Task execution order:\n");
    printf("Task  Id  Time  Priority\n");
    int total_time = 0;
    for (int i = 0; i < task_list.num_tasks; i++) {
        printf("%-5d %-3d %-5d %-3d\n",
               i+1, task_list.tasks[i].task_id, task_list.tasks[i].task_time, task_list.tasks[i].priority);
        total_time += task_list.tasks[i].task_time;
    }
    printf("Total execution time: %d\n", total_time);

    return 0;
}