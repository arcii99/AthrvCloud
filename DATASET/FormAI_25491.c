//FormAI DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Task {
    int id;
    char name[50];
    int seconds;
    time_t start_time; // Clock time when the task starts
} Task;

void print_task(Task *task) {
    printf("Task %d: %s - Duration: %d seconds\n", task->id, task->name, task->seconds);
}

void execute_task(Task *task) {
    time_t current_time;
    time(&current_time);
    printf("Executing Task %d: %s at %s", task->id, task->name, ctime(&current_time));
    task->start_time = current_time;
    sleep(task->seconds); // Simulates the task execution time
    printf("Task %d: %s completed in %d seconds\n", task->id, task->name, task->seconds);
}

int main() {
    srand(time(NULL)); // Seed for the random generator
    Task first_task = {1, "Backup Data", rand() % 10 + 5, 0};
    Task second_task = {2, "Clean Database", rand() % 20 + 10, 0};
    Task third_task = {3, "Send Email", rand() % 5 + 2, 0};
    Task tasks[3] = {first_task, second_task, third_task};
    int num_tasks = 3;

    printf("Scheduled Tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        print_task(&tasks[i]);
    }

    while (1) {
        for (int i = 0; i < num_tasks; i++) {
            time_t current_time;
            time(&current_time);
            if (difftime(current_time, tasks[i].start_time) >= tasks[i].seconds) {
                execute_task(&tasks[i]);
            }
        }

        printf("All tasks have been executed.\n");
        break;
    }

    return 0;
}