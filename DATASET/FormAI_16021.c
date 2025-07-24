//FormAI DATASET v1.0 Category: Task Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum {
    TASK_1,
    TASK_2,
    TASK_3,
    TASK_COUNT
};

const int task_delay[] = { 3, 4, 5 };

void task_1(void) {
    printf("Task 1 running... Done!\n");
}

void task_2(void) {
    printf("Task 2 running... Done!\n");
}

void task_3(void) {
    printf("Task 3 running... Done!\n");
}

void execute_task(int task_id) {
    switch (task_id) {
        case TASK_1:
            task_1();
            break;
        case TASK_2:
            task_2();
            break;
        case TASK_3:
            task_3();
            break;
    }
}

int main(void) {
    srand(time(NULL));
    int task_queue[TASK_COUNT] = {0};
    int task_delay_count[TASK_COUNT] = {0};
    int task_running = -1;
    int task_completed_count = 0;

    printf("Task Scheduler Example Program\n\n");

    while (task_completed_count < TASK_COUNT) {
        int empty_count = 0;
        for (int i = 0; i < TASK_COUNT; i++) {
            if (task_delay[i] <= task_delay_count[i]) {
                task_queue[empty_count++] = i;
            } else {
                task_delay_count[i]++;
            }
        }
        if (empty_count > 0 && task_running == -1) {
            int task_id = task_queue[rand() % empty_count];
            task_running = task_id;
            printf("Starting task %d...\n", task_id + 1);
            task_delay_count[task_id] = 0;
        } else if (task_running != -1) {
            execute_task(task_running);
            printf("Task %d completed!\n\n", task_running + 1);
            task_running = -1;
            task_completed_count++;
        } else {
            printf("All tasks are pending...\n");
        }
    }

    printf("All tasks completed successfully!\n");

    return EXIT_SUCCESS;
}