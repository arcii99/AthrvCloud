//FormAI DATASET v1.0 Category: Task Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TASK_COUNT 5

typedef struct Task {
    int id;
    int priority;
    int start_time;
    int duration;
} Task;

void add_task(Task* tasks, int id, int priority, int start_time, int duration) {
    tasks->id = id;
    tasks->priority = priority;
    tasks->start_time = start_time;
    tasks->duration = duration;
}

void schedule_tasks(Task* tasks, int task_count) {
    // Sort tasks by their priority
    for (int i = 0; i < task_count - 1; i++) {
        for (int j = i + 1; j < task_count; j++) {
            if (tasks[i].priority < tasks[j].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    // Schedule tasks
    printf("Task Schedule\n");
    int current_time = 0;
    for (int i = 0; i < task_count; i++) {
        int task_start = tasks[i].start_time;
        if (current_time < task_start) {
            // Wait until task start time
            printf("Idle for %ds\n", task_start - current_time);
            current_time = task_start;
        }
        printf("Task %d started\n", tasks[i].id);
        current_time += tasks[i].duration;
        printf("Task %d finished at %ds\n", tasks[i].id, current_time);
    }
}

int main() {
    Task tasks[TASK_COUNT];

    // Add tasks to array
    add_task(&tasks[0], 1, 3, 0, 5);
    add_task(&tasks[1], 2, 2, 3, 7);
    add_task(&tasks[2], 3, 1, 10, 3);
    add_task(&tasks[3], 4, 4, 15, 6);
    add_task(&tasks[4], 5, 2, 20, 4);

    // Schedule tasks
    schedule_tasks(tasks, TASK_COUNT);

    return 0;
}