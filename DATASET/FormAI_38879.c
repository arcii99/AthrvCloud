//FormAI DATASET v1.0 Category: Task Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 5

typedef struct {
    int task_id;
    int priority;
    int execution_time;
} task_t;

void shuffle_array(int *array, int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void initialize_tasks(task_t *tasks, int n) {
    int priority_values[MAX_PRIORITY] = {1, 2, 3, 4, 5};
    shuffle_array(priority_values, MAX_PRIORITY);

    for (int i = 0; i < n; i++) {
        tasks[i].task_id = i + 1;
        tasks[i].priority = priority_values[i % MAX_PRIORITY];
        tasks[i].execution_time = (rand() % 10) + 1;
    }
}

void print_task(task_t task) {
    printf("Task %d:\nPriority: %d\nExecution Time: %d\n\n", task.task_id, task.priority, task.execution_time);
}

void print_tasks(task_t *tasks, int n) {
    for (int i = 0; i < n; i++) {
        print_task(tasks[i]);
    }
}

void perform_task(task_t task) {
    printf("Performing Task %d...\n", task.task_id);
    for (int i = 1; i <= task.execution_time; i++) {
        printf("Execution Time: %d/%d\n", i, task.execution_time);
        sleep(1);
    }
    printf("Task %d completed!\n", task.task_id);
}

void schedule_tasks(task_t *tasks, int n) {
    int current_priority = MAX_PRIORITY;
    while (current_priority >= 1) {
        printf("Current Priority: %d\n", current_priority);
        for (int i = 0; i < n; i++) {
            if (tasks[i].priority == current_priority) {
                printf("Scheduling Task %d...\n", tasks[i].task_id);
                perform_task(tasks[i]);
            }
        }
        current_priority--;
    }
}

int main() {
    task_t tasks[MAX_TASKS];
    initialize_tasks(tasks, MAX_TASKS);
    printf("Initialized Tasks:\n");
    print_tasks(tasks, MAX_TASKS);
    printf("Scheduling Tasks...\n");
    schedule_tasks(tasks, MAX_TASKS);
    printf("All tasks completed!\n");
    return 0;
}