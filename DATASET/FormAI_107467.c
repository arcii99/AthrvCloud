//FormAI DATASET v1.0 Category: Task Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_LEN 50

typedef struct {
    char name[MAX_LEN]; // task name
    int priority; // task priority
    int time; // time required to complete task
    bool done; // true if task is completed
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

// function prototypes
void print_menu();
void add_task();
void remove_task();
void display_tasks();
void mark_as_done();

int main() {
    int choice;

    while (true) {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                remove_task();
                break;
            case 3:
                display_tasks();
                break;
            case 4:
                mark_as_done();
                break;
            case 5:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}

void print_menu() {
    printf("\n**** Task Scheduler Menu ****\n");
    printf("1. Add a task\n");
    printf("2. Remove a task\n");
    printf("3. Display all tasks\n");
    printf("4. Mark task as done\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void add_task() {
    if (num_tasks >= MAX_TASKS) {
        printf("\nTask list is full. Cannot add new task.\n");
        return;
    }

    printf("\nEnter task details:\n");
    printf("Name: ");
    scanf("%s", tasks[num_tasks].name);
    printf("Priority (1-10): ");
    scanf("%d", &tasks[num_tasks].priority);
    printf("Time required (in minutes): ");
    scanf("%d", &tasks[num_tasks].time);
    tasks[num_tasks].done = false;

    printf("\nTask added successfully!\n");

    num_tasks++;
}

void remove_task() {
    if (num_tasks == 0) {
        printf("\nTask list is empty. Cannot remove task.\n");
        return;
    }

    int index;
    printf("\nEnter index of task to be removed (1-%d): ", num_tasks);
    scanf("%d", &index);

    if (index < 1 || index > num_tasks) {
        printf("\nInvalid index. Try again.\n");
        return;
    }

    for (int i = index-1; i < num_tasks-1; i++) {
        strcpy(tasks[i].name, tasks[i+1].name);
        tasks[i].priority = tasks[i+1].priority;
        tasks[i].time = tasks[i+1].time;
        tasks[i].done = tasks[i+1].done;
    }

    num_tasks--;

    printf("\nTask removed successfully!\n");
}

void display_tasks() {
    if (num_tasks == 0) {
        printf("\nNo tasks added yet.\n");
        return;
    }

    printf("\nTask List:\n");
    printf("Index\tName\t\tPriority\tTime required\tDone?\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d\t%s\t\t%d\t\t%d\t\t%s\n", i+1, tasks[i].name, tasks[i].priority, tasks[i].time, tasks[i].done ? "Yes" : "No");
    }
}

void mark_as_done() {
    if (num_tasks == 0) {
        printf("\nNo tasks added yet.\n");
        return;
    }

    int index;
    printf("\nEnter the index of the task to be marked as done (1-%d): ", num_tasks);
    scanf("%d", &index);

    if (index < 1 || index > num_tasks) {
        printf("\nInvalid index. Try again.\n");
        return;
    }

    tasks[index-1].done = true;

    printf("\nTask marked as done!\n");
}