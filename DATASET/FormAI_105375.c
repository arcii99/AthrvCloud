//FormAI DATASET v1.0 Category: Task Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct task {
    int id;
    void (*function)(void);
    time_t start_time;
    time_t end_time;
} Task;

Task task_list[MAX_TASKS];
int num_tasks = 0;

void task1() {
    printf("Task 1 Executed!\n");
}

void task2() {
    printf("Task 2 Executed!\n");
}

void add_task(void (*function)(void)) {
    if (num_tasks == MAX_TASKS) {
        printf("Error: Task List Full\n");
        return;
    }
    Task task;
    task.id = num_tasks;
    task.function = function;
    task.start_time = time(NULL);
    task_list[num_tasks] = task;
    num_tasks++;
}

void remove_task(int task_id) {
    Task *task = NULL;
    for (int i = 0; i < num_tasks; i++) {
        if (task_list[i].id == task_id) {
            task = &task_list[i];
            break;
        }
    }
    if (task == NULL) {
        printf("Error: Task not Found!\n");
        return;
    }
    task->function = NULL;
    task->start_time = 0;
    task->end_time = 0;
    num_tasks--;
}

void execute_tasks() {
    printf("Executing Tasks...\n");
    for (int i = 0; i < MAX_TASKS; i++) {
        if (task_list[i].function != NULL) {
            task_list[i].function();
            task_list[i].end_time = time(NULL);
        }
    }
}

void *schedule_tasks(void *args) {
    int interval = *(int*)args;
    while (1) {
        printf("Schedule Loop...\n");
        execute_tasks();
        printf("Wait for %d seconds...\n", interval);
        sleep(interval);
    }
}

int main() {
    pthread_t thread_id;
    int interval = 5;

    add_task(task1);
    add_task(task2);

    if (pthread_create(&thread_id, NULL, schedule_tasks, &interval) != 0) {
        printf("Error: Thread Creation Failed!\n");
        return 1;
    }

    printf("Task Scheduler is Running...\n");

    while (1) {
        char cmd;
        printf("Enter Command: ");
        scanf("%c", &cmd);
        switch(cmd) {
            case 'a':
                add_task(task1);
                break;
            case 'b':
                add_task(task2);
                break;
            case 'r':
                int task_id;
                printf("Enter Task ID to Remove: ");
                scanf("%d", &task_id);
                remove_task(task_id);
                break;
            case 'q':
                printf("Exiting Task Scheduler...\n");
                pthread_cancel(thread_id);
                pthread_join(thread_id, NULL);
                return 0;
            default:
                printf("Invalid Command!\n");
                break;
        }
        while ((getchar()) != '\n');
    }
    return 0;
}