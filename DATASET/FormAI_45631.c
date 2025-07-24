//FormAI DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TASKS 5

typedef struct Task {
    int id;
    int priority;
    int interval;
    time_t last_run;
    void (*function)();
} Task;

Task tasks[NUM_TASKS];

void task1() {
    printf("Task 1 is running!\n");
}

void task2() {
    printf("Task 2 is running!\n");
}

void task3() {
    printf("Task 3 is running!\n");
}

void task4() {
    printf("Task 4 is running!\n");
}

void task5() {
    printf("Task 5 is running!\n");
}

void initialize_tasks() {
    tasks[0] = (Task){ 1, 3, 5, 0, task1 };
    tasks[1] = (Task){ 2, 2, 8, 0, task2 };
    tasks[2] = (Task){ 3, 1, 10, 0, task3 };
    tasks[3] = (Task){ 4, 4, 3, 0, task4 };
    tasks[4] = (Task){ 5, 5, 7, 0, task5 };
}

int get_time_in_seconds() {
    return (int)time(NULL);
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void run_task(Task task) {
    printf("Running task %d...\n", task.id);
    task.function();
    task.last_run = get_time_in_seconds();
}

int can_run_task(Task task) {
    int interval_seconds = task.interval;
    int elapsed_seconds = get_time_in_seconds() - task.last_run;
    if (elapsed_seconds >= interval_seconds) {
        return 1;
    }
    return 0;
}

int compare_tasks(const void* a, const void* b) {
    Task task_a = *((Task*)a);
    Task task_b = *((Task*)b);
    return task_b.priority - task_a.priority;
}

void run_tasks() {
    qsort(tasks, NUM_TASKS, sizeof(Task), compare_tasks);
    for (int i = 0; i < NUM_TASKS; i++) {
        if (can_run_task(tasks[i])) {
            run_task(tasks[i]);
        }
    }
}

int main() {
    srand(time(NULL));
    initialize_tasks();
    while (1) {
        run_tasks();
        int sleep_time = get_random_number(1, 5);
        printf("Sleeping for %d seconds...\n", sleep_time);
        sleep(sleep_time);
    }
    return 0;
}