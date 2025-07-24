//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TIME 60

// Struct to hold information about a task
typedef struct Task {
    int id;
    int priority;
    int arrival_time;
    int execution_time;
} Task;

// Function to generate a random integer between a and b
int random_int(int a, int b) {
    return a + (rand() % (b - a + 1));
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the task list
    Task tasks[MAX_TASKS];
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].id = i;
        tasks[i].priority = random_int(0, 10);
        tasks[i].arrival_time = random_int(0, MAX_TIME);
        tasks[i].execution_time = random_int(1, 10);
    }

    // Print the task list
    printf("TASKS:\n");
    for (int i = 0; i < MAX_TASKS; i++) {
        printf("Task %d: priority=%d, arrival_time=%d, execution_time=%d\n", 
                tasks[i].id, tasks[i].priority, tasks[i].arrival_time, tasks[i].execution_time);
    }

    // Implement a priority-based task scheduler
    int time = 0;
    Task *queue[MAX_TASKS];
    int queue_len = 0;
    Task *current_task = NULL;
    while (time <= MAX_TIME) {
        // Check if any tasks have arrived
        for (int i = 0; i < MAX_TASKS; i++) {
            Task *task = &tasks[i];
            if (task->arrival_time == time) {
                queue[queue_len++] = task;
            }
        }

        // Find the task with the highest priority that is ready to run
        int highest_priority = -1;
        for (int i = 0; i < queue_len; i++) {
            Task *task = queue[i];
            if (task->priority > highest_priority && task->execution_time > 0) {
                highest_priority = task->priority;
                current_task = task;
            }
        }

        // Execute the current task for one time unit
        if (current_task != NULL) {
            printf("Time %d: Running Task %d (priority=%d, arrival_time=%d, execution_time=%d)\n", 
                    time, current_task->id, current_task->priority, current_task->arrival_time, current_task->execution_time);
            current_task->execution_time--;
            if (current_task->execution_time == 0) {
                printf("Time %d: Completed Task %d\n", time, current_task->id);
                current_task = NULL;
            }
        } else {
            printf("Time %d: No tasks are ready to run\n", time);
        }

        // Remove completed tasks from the queue
        for (int i = 0; i < queue_len; i++) {
            Task *task = queue[i];
            if (task->execution_time == 0) {
                queue[i] = NULL;
            }
        }
        int j = 0;
        for (int i = 0; i < queue_len; i++) {
            if (queue[i] != NULL) {
                queue[j++] = queue[i];
            }
        }
        queue_len = j;

        // Increment time
        time++;
    }

    return 0;
}