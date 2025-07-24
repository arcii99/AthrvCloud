//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

typedef struct task {
    char name[50];
    int priority;
    int deadline;
    int duration;
    struct task *next;
} Task;

Task *head = NULL;
Task *tail = NULL;

void add_task(char *name, int priority, int deadline, int duration) {
    Task *new_task = (Task *)malloc(sizeof(Task));
    if (new_task == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->deadline = deadline;
    new_task->duration = duration;
    new_task->next = NULL;
    if (head == NULL) {
        head = new_task;
    }
    else {
        tail->next = new_task;
    }
    tail = new_task;
}

void print_task(Task *task) {
    printf("%s (%d) - Deadline: %d, Duration: %d\n", task->name, task->priority, task->deadline, task->duration);
}

void schedule_tasks() {
    Task *current_task = head;
    while (current_task != NULL) {
        Task *next_task = current_task->next;
        while (next_task != NULL) {
            if (current_task->deadline > next_task->deadline) {
                Task temp = *current_task;
                *current_task = *next_task;
                *next_task = temp;
            }
            next_task = next_task->next;
        }
        current_task = current_task->next;
    }
    current_task = head;
    while (current_task != NULL) {
        printf("Scheduled task: ");
        print_task(current_task);
        current_task = current_task->next;
    }
}

int main() {
    add_task("Task 1", 5, 10, 2);
    add_task("Task 2", 3, 5, 3);
    add_task("Task 3", 2, 8, 1);
    add_task("Task 4", 4, 12, 4);
    add_task("Task 5", 1, 3, 2);
    printf("Unscheduled tasks:\n");
    Task *current_task = head;
    while (current_task != NULL) {
        print_task(current_task);
        current_task = current_task->next;
    }
    printf("Scheduled tasks:\n");
    schedule_tasks();
    return 0;
}