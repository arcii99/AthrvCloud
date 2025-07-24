//FormAI DATASET v1.0 Category: Task Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct task_s {
    int id;
    int priority;
    int execute_time;
} task_t;

task_t task_queue[10];
int task_count = 0;
int clock_time = 0;

void add_task(int id, int priority, int execute_time) {
    task_t new_task = {
        .id = id,
        .priority = priority,
        .execute_time = execute_time
    };
    task_queue[task_count++] = new_task;
}

void execute_task(task_t task) {
    printf("Task %d is executing ... (Priority: %d, Execution Time: %d)\n", task.id, task.priority, task.execute_time);
}

task_t get_highest_priority_task() {
    task_t highest_priority_task = {
        .id = -1,
        .priority = 9999,
        .execute_time = -1
    };
    for (int i = 0; i < task_count; i++) {
        if (task_queue[i].priority < highest_priority_task.priority) {
            highest_priority_task = task_queue[i];
        }
    }
    return highest_priority_task;
}

int main() {
    srand(time(NULL));
    add_task(1, 1, 5);
    add_task(2, 2, 7);
    add_task(3, 3, 2);
    add_task(4, 1, 3);
    add_task(5, 2, 4);
    add_task(6, 3, 1);
    add_task(7, 1, 2);
    add_task(8, 2, 4);
    add_task(9, 3, 5);
    add_task(10, 1, 3);
    while (task_count > 0) {
        task_t current_task = get_highest_priority_task();
        clock_time += current_task.execute_time;
        execute_task(current_task);
        for (int i = 0; i < task_count; i++) {
            if (task_queue[i].id == current_task.id) {
                for (int j = i + 1; j < task_count; j++) {
                    task_queue[j - 1] = task_queue[j];
                }
                task_count--;
                break;
            }
        }
    }
    printf("All tasks completed! Total clock time: %d\n", clock_time);
    return 0;
}