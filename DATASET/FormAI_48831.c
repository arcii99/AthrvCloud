//FormAI DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef void (*task_func_t)(void);

typedef struct task_task {
    task_func_t func;
    struct task_task *next;
    time_t time;
} task_t;

task_t *task_list = NULL;

void add_task(time_t time, task_func_t func) {
    task_t *new_task = malloc(sizeof(task_t));
    new_task->func = func;
    new_task->next = NULL;
    new_task->time = time;
    if (task_list == NULL || difftime(time, task_list->time) < 0) {
        new_task->next = task_list;
        task_list = new_task;
        return;
    }
    task_t *current = task_list;
    while (current->next != NULL && difftime(time, current->next->time) > 0) {
        current = current->next;
    }
    new_task->next = current->next;
    current->next = new_task;
}

void run_task(void) {
    task_t *task = task_list;
    if (task != NULL) {
        task->func();
        task_list = task_list->next;
        free(task);
    }
}

void clean_tasks(void) {
    while (task_list != NULL && difftime(task_list->time, time(NULL)) < 0) {
        task_t *task = task_list;
        task_list = task_list->next;
        free(task);
    }
}

void print_tasks(void) {
    task_t *current = task_list;
    printf("Task list:\n");
    while (current != NULL) {
        printf("%li\t", current->time);
        current = current->next;
    }
    printf("\n");
}

void task1(void) {
    printf("Task 1 done!\n");
    add_task(time(NULL) + 3, task1);
}

void task2(void) {
    printf("Task 2 done!\n");
    add_task(time(NULL) + 5, task2);
}

void task3(void) {
    printf("Task 3 done!\n");
    add_task(time(NULL) + 2, task3);
}

int main(void) {
    add_task(time(NULL) + 3, task1);
    add_task(time(NULL) + 5, task2);
    add_task(time(NULL) + 2, task3);

    while (true) {
        clean_tasks();
        print_tasks();
        run_task();
        sleep(1);
    }

    return 0;
}