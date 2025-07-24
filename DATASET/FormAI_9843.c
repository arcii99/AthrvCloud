//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    int id;
    time_t start_time;
    time_t end_time;
    void (*action)();
} Task;

Task task_list[MAX_TASKS];
int num_tasks = 0;

void add_task(Task t) {
    if (num_tasks == MAX_TASKS) {
        printf("Error: maximum number of tasks reached\n");
        return;
    }

    task_list[num_tasks++] = t;
}

void execute_task(Task t) {
    t.start_time = time(NULL);
    printf("Executing task %d...\n", t.id);
    t.action();
    t.end_time = time(NULL);
}

void task_scheduler() {
    int i;
    for (i = 0; i < num_tasks; i++) {
        execute_task(task_list[i]);
        printf("Task %d completed in %ld seconds\n", task_list[i].id, task_list[i].end_time - task_list[i].start_time);
    }
}

void task_1() {
    printf("This is task 1\n");
}

void task_2() {
    printf("This is task 2\n");
}

int main() {
    Task t1 = {1, 0, 0, &task_1};
    Task t2 = {2, 0, 0, &task_2};

    add_task(t1);
    add_task(t2);

    task_scheduler();

    return 0;
}