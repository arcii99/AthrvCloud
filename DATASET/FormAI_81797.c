//FormAI DATASET v1.0 Category: Task Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct task {
    int id;
    int priority;
    time_t start_time;
    time_t end_time;
} task_t;

void schedule_task(void (*task_handler)(task_t), task_t task, int delay) {
    time_t current_time = time(NULL);
    task.start_time = current_time + delay;

    printf("Task %d scheduled at %s", task.id, ctime(&task.start_time));
    while (difftime(time(NULL), task.start_time) < 0) {}

    printf("Task %d started at %s", task.id, ctime(&current_time));
    task_handler(task);
    task.end_time = time(NULL);

    printf("Task %d executed successfully at %s", task.id, ctime(&task.end_time));
}

void handle_task(task_t task) {
    printf("Executing task %d with priority %d\n", task.id, task.priority);
}

int main() {
    task_t task1 = {1, 3, 0, 0};
    task_t task2 = {2, 2, 0, 0};
    task_t task3 = {3, 1, 0, 0};

    // Schedule task1 with no delay
    schedule_task(handle_task, task1, 0);

    // Schedule task2 with 5 seconds delay
    schedule_task(handle_task, task2, 5);

    // Schedule task3 with 10 seconds delay
    schedule_task(handle_task, task3, 10);

    return 0;
}