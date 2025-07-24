//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scientific
/*
 * C Task Scheduler Example Program
 * Author: AI Chatbot
 * Date: October 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LEN 50
#define TASK_RUNNING 1
#define TASK_STOPPED 0

// Structure to store a single task
typedef struct {
    char name[MAX_TASK_NAME_LEN];
    int interval; // in seconds
    int status;
    void (*func)();
} task_t;

// Array to store all tasks
task_t tasks[MAX_TASKS];
int num_tasks = 0;

// Function to add a new task
void add_task() {
    char name[MAX_TASK_NAME_LEN];
    int interval;
    printf("Enter task name: ");
    scanf("%s", name);
    printf("Enter task interval (in seconds): ");
    scanf("%d", &interval);
    tasks[num_tasks].interval = interval;
    tasks[num_tasks].status = TASK_RUNNING;
    strcpy(tasks[num_tasks].name, name);
    num_tasks++;
    printf("Task added successfully.\n");
}

// Function to remove a task
void remove_task() {
    int task_idx;
    printf("Enter task index to remove: ");
    scanf("%d", &task_idx);
    if (task_idx >= num_tasks || task_idx < 0) {
        printf("Invalid task index.\n");
        return;
    }
    for (int i = task_idx; i < num_tasks - 1; i++) {
        tasks[i] = tasks[i + 1]; // Shift all tasks left
    }
    num_tasks--;
    printf("Task removed successfully.\n");
}

// Function to print all tasks
void print_tasks() {
    printf("Task List:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d: %s (every %d seconds)\n", i, tasks[i].name, tasks[i].interval);
    }
}

// Helper function to execute a single task
void execute_task(task_t *t) {
    t->func();
}

// Signal handler for SIGALRM
void handler(int signal) {
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].status == TASK_RUNNING) {
            if ((time(NULL) % tasks[i].interval) == 0) {
                execute_task(&tasks[i]);
            }
        }
    }
    alarm(1); // Set another alarm in 1 second
}

// Function to start the task scheduler
void start_scheduler() {
    printf("Starting task scheduler...\n");
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &handler;
    sigaction(SIGALRM, &sa, NULL);
    alarm(1); // Set initial alarm in 1 second
    while (1) {
        sleep(1); // Wait for signals
    }
}

// Example tasks
void task1_func() {
    printf("Task 1 executed.\n");
}

void task2_func() {
    printf("Task 2 executed.\n");
}

void task3_func() {
    printf("Task 3 executed.\n");
}

// Main function
int main() {
    // Add example tasks
    tasks[0].interval = 5;
    tasks[0].status = TASK_RUNNING;
    strcpy(tasks[0].name, "Task 1");
    tasks[0].func = &task1_func;

    tasks[1].interval = 10;
    tasks[1].status = TASK_RUNNING;
    strcpy(tasks[1].name, "Task 2");
    tasks[1].func = &task2_func;

    num_tasks = 2;

    // Start task scheduler
    start_scheduler();

    return 0;
}