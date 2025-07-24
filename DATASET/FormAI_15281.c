//FormAI DATASET v1.0 Category: Task Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct task_s {
    char *name;
    int priority;
    void (*function)();
    struct task_s *next;
} task_t;

task_t *scheduler = NULL;

task_t* create_task(char *name, int priority, void (*func)()) {
    task_t *task = (task_t *) malloc(sizeof(task_t));
    task->name = (char *) malloc(strlen(name) + 1);
    strcpy(task->name, name);
    task->priority = priority;
    task->function = func;
    task->next = NULL;

    return task;
}

void add_task(task_t *task) {
    if(!scheduler) {
        scheduler = task;
    } else {
        task_t *prev = NULL;
        task_t *curr = scheduler;

        while(curr && task->priority < curr->priority) {
            prev = curr;
            curr = curr->next;
        }

        if(prev) {
            prev->next = task;
        } else {
            scheduler = task;
        }

        task->next = curr;
    }
}

void remove_task(char *name) {
    task_t *prev = NULL;
    task_t *curr = scheduler;

    while(curr && strcmp(curr->name, name)) {
        prev = curr;
        curr = curr->next;
    }

    if(curr) {
        if(prev) {
            prev->next = curr->next;
        } else {
            scheduler = curr->next;
        }

        free(curr->name);
        free(curr);
    }
}

void execute_tasks() {
    task_t *curr = scheduler;

    while(curr) {
        printf("Executing task: %s\n", curr->name);
        curr->function();
        curr = curr->next;
    }
}

void task1() {
    printf("Task 1 executed!\n");
}

void task2() {
    printf("Task 2 executed!\n");
}

int main() {
    add_task(create_task("Task 1", 2, task1));
    add_task(create_task("Task 2", 1, task2));

    execute_tasks();

    remove_task("Task 2");

    execute_tasks();

    return 0;
}