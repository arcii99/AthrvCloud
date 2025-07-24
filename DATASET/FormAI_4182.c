//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10          // maximum number of tasks
#define MAX_SCHEDULE_TIME 100 // maximum time to run scheduler

int tasks_completed = 0;      // total number of tasks completed

// function pointer type
typedef void (*TaskFn)(void);

// task struct
typedef struct {
    TaskFn func;
    int priority;
    int delay;
} Task;

// queue struct
typedef struct {
    Task tasks[MAX_TASKS];
    int count;
} TaskQueue;

// function to add task to queue
void add_task(TaskQueue* queue, TaskFn func, int priority, int delay) {
    // only add task if there is room in queue
    if (queue->count < MAX_TASKS) {
        queue->tasks[queue->count].func = func;
        queue->tasks[queue->count].priority = priority;
        queue->tasks[queue->count].delay = delay;
        queue->count++;
    }
}

// function to remove task from queue
void remove_task(TaskQueue* queue, int i) {
    // shift tasks after i to the left to fill the gap
    for (int j = i; j < queue->count - 1; j++) {
        queue->tasks[j] = queue->tasks[j + 1];
    }
    queue->count--;
}

// function to compare two tasks by priority
int compare_tasks(const void* a, const void* b) {
    Task* task_a = (Task*)a;
    Task* task_b = (Task*)b;

    if (task_a->priority > task_b->priority) {
        return -1;
    } else if (task_a->priority < task_b->priority) {
        return 1;
    } else {
        return 0;
    }
}

// function to run scheduler
void run_scheduler(TaskQueue* queue) {
    printf("Running task scheduler:\n");

    int time = 0;

    // loop until all tasks complete or until maximum time is reached
    while (tasks_completed < queue->count && time < MAX_SCHEDULE_TIME) {
        // delay for 1 second
        sleep(1);
        time++;

        // decrement delays on tasks
        for (int i = 0; i < queue->count; i++) {
            if (queue->tasks[i].delay > 0) {
                queue->tasks[i].delay--;
            }
        }

        // sort tasks by priority
        qsort(queue->tasks, queue->count, sizeof(Task), compare_tasks);

        // execute tasks with zero delay
        for (int i = 0; i < queue->count; i++) {
            if (queue->tasks[i].delay == 0) {
                printf("Running task %d...\n", i + 1);
                queue->tasks[i].func();
                tasks_completed++;
                remove_task(queue, i);
            }
        }
    }

    // check if all tasks completed
    if (tasks_completed == queue->count) {
        printf("All tasks completed.\n");
    } else {
        printf("Maximum time limit reached.\n");
    }
}

// example task functions
void task1() {
    printf("Task 1 executed.\n");
}

void task2() {
    printf("Task 2 executed.\n");
}

void task3() {
    printf("Task 3 executed.\n");
}

void task4() {
    printf("Task 4 executed.\n");
}

int main() {
    // seed random number generator with current time
    srand(time(NULL));

    // create tasks and add to queue
    TaskQueue queue = {0};
    add_task(&queue, task1, rand() % 5 + 1, rand() % 10);
    add_task(&queue, task2, rand() % 5 + 1, rand() % 10);
    add_task(&queue, task3, rand() % 5 + 1, rand() % 10);
    add_task(&queue, task4, rand() % 5 + 1, rand() % 10);

    // run scheduler
    run_scheduler(&queue);

    return 0;
}