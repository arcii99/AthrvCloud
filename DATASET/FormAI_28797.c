//FormAI DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct task_struct {
    int id;
    char name[30];
    int interval;
    time_t last_executed;
    void (*func)(void);
    struct task_struct *next;
} Task;

Task *head = NULL;
Task *tail = NULL;
int task_id = 0;

void add_task(char name[], int interval, void (*func)(void)) {
    Task *new_task = (Task*)malloc(sizeof(Task));
    new_task->id = ++task_id;
    strcpy(new_task->name, name);
    new_task->interval = interval;
    new_task->last_executed = time(NULL);
    new_task->func = func;
    new_task->next = NULL;
    if (head == NULL) {
        head = tail = new_task;
    } else {
        tail->next = new_task;
        tail = new_task;
    }
}

void remove_task(int id) {
    Task *curr_task = head;
    Task *prev_task = NULL;
    
    while (curr_task) {
        if (curr_task->id == id) {
            if (curr_task == head)
                head = curr_task->next;
            else
                prev_task->next = curr_task->next;
            free(curr_task);
            return;
        }
        prev_task = curr_task;
        curr_task = curr_task->next;
    }
}

void run_task(Task *task) {
    printf("Executing task %d: %s\n", task->id, task->name);
    task->func();
    task->last_executed = time(NULL);
}

void run_all_tasks() {
    Task *curr_task = head;

    while (curr_task) {
        if (difftime(time(NULL), curr_task->last_executed) >= curr_task->interval) {
            run_task(curr_task);
        }
        curr_task = curr_task->next;
    }
}

void task1() {
    printf("This is task 1\n");
}

void task2() {
    printf("This is task 2\n");
}

void task3() {
    printf("This is task 3\n");
}

int main() {
    add_task("Task 1", 5, task1);
    add_task("Task 2", 10, task2);
    add_task("Task 3", 15, task3);

    while (1) {
        run_all_tasks();
        sleep(1);
    }

    return 0;
}