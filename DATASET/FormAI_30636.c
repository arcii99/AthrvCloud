//FormAI DATASET v1.0 Category: Task Scheduler ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define MAX_TASKS 10
#define INTERVAL 1 // in seconds

typedef struct task {
    int id;
    int time_left;
    int interval;
    void (*func)();
} Task;

Task task_list[MAX_TASKS];

void register_task(Task t) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (task_list[i].func == NULL) {
            task_list[i] = t;
            return;
        }
    }
    printf("Error: Task list is full\n");
    exit(1);
}

void cancel_task(Task t) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (task_list[i].id == t.id) {
            task_list[i].func = NULL;
            return;
        }
    }
    printf("Error: Task not found\n");
}

void schedule_task(Task t) {
    t.id = rand(); // generate unique task id
    register_task(t);
}

void start_scheduler() {
    int count = 0;
    while (1) {
        // Check for completed tasks and execute them
        for (int i = 0; i < MAX_TASKS; i++) {
            if (task_list[i].time_left == 0 && task_list[i].func != NULL) {
                task_list[i].func();
                task_list[i].time_left = task_list[i].interval;
            }
        }

        // Wait for interval time
        sleep(INTERVAL);

        // Decrement time left for all active tasks
        count += INTERVAL;
        for (int i = 0; i < MAX_TASKS; i++) {
            if (task_list[i].func != NULL) {
                task_list[i].time_left -= INTERVAL;
            }
        }

        // Print status once every 30 seconds
        if (count == 30) {
            printf("\nCurrent Status:\n");
            for (int i = 0; i < MAX_TASKS; i++) {
                if (task_list[i].func != NULL) {
                    printf("Task %d: Time Left = %d\n", task_list[i].id, task_list[i].time_left);
                }
            }
            count = 0;
        }
    }
}

void example_task_func() {
    printf("This is an example task\n");
}

int main() {
    // Register example task
    Task t;
    t.time_left = 5;
    t.interval = 10;
    t.func = example_task_func;
    schedule_task(t);

    // Start scheduler
    printf("Starting Scheduler...\n\n");
    start_scheduler();
    return 0;
}