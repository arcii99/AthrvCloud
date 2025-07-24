//FormAI DATASET v1.0 Category: Task Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TASKS 5
#define INTERVAL 500
#define MAX_EXECUTION_TIME 3000

typedef struct {
    int id;
    int next_execution_time;
} Task;

int get_random_execution_time() {
    return rand() % MAX_EXECUTION_TIME + 1;
}

Task create_task(int id) {
    Task task;
    task.id = id;
    task.next_execution_time = INTERVAL;
    return task;
}

int main() {
    srand(time(NULL));
    Task task_list[TASKS];
    int current_time = 0;

    // Create task list
    for (int i = 0; i < TASKS; i++)
        task_list[i] = create_task(i + 1);

    // Execute tasks
    while (1) {
        int shortest_time = MAX_EXECUTION_TIME + 1;
        int shortest_time_task_id = -1;

        printf("Current time: %d\n", current_time);

        for (int i = 0; i < TASKS; i++) {
            Task *task = &task_list[i];

            if (task->next_execution_time <= current_time) {
                printf("Executing task %d...\n", task->id);
                task->next_execution_time = current_time + INTERVAL + get_random_execution_time();
            } else {
                int remaining_time = task->next_execution_time - current_time;

                if (remaining_time < shortest_time) {
                    shortest_time = remaining_time;
                    shortest_time_task_id = task->id;
                }
            }
        }

        if (shortest_time_task_id != -1) {
            printf("Next task to execute: %d in %d milliseconds\n",
                   shortest_time_task_id, shortest_time);
            current_time += shortest_time;
        } else {
            printf("No tasks found. Exiting...\n");
            break;
        }

        printf("\n");
    }

    return 0;
}