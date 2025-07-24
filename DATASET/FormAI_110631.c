//FormAI DATASET v1.0 Category: Task Scheduler ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_TASKS 10
#define MAX_TASK_TIME 3

typedef struct {
    int task_id;
    int task_duration;
    int task_status;
} Task;

void *execute_task(void *task_ptr) {
    Task *task = (Task *) task_ptr;
    printf("Executing task %d for %d seconds...\n", task->task_id, task->task_duration);
    sleep(task->task_duration);
    printf("Task %d complete!\n", task->task_id);
    task->task_status = 1;
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    pthread_t threads[NUM_TASKS];
    int i = 0;
    Task task_list[NUM_TASKS];

    // Initialize task list
    for (i = 0; i < NUM_TASKS; i++) {
        task_list[i].task_id = i + 1;
        task_list[i].task_duration = rand() % MAX_TASK_TIME + 1;
        task_list[i].task_status = 0;
    }

    // Execute tasks in a distributed fashion
    for (i = 0; i < NUM_TASKS; i++) {
        pthread_create(&threads[i], NULL, execute_task, (void *)&task_list[i]);
        usleep(50000); // sleep for 50 ms to simulate scheduling delay
    }

    // Wait for all tasks to complete
    for (i = 0; i < NUM_TASKS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print status of each task
    for (i = 0; i < NUM_TASKS; i++) {
        if (task_list[i].task_status == 0) {
            printf("Task %d: FAILED\n", task_list[i].task_id);
        } else {
            printf("Task %d: SUCCESS\n", task_list[i].task_id);
        }
    }

    return 0;
}