//FormAI DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 5

void task_one() {
    printf("[TASK ONE] Running...\n");
}

void task_two() {
    printf("[TASK TWO] Running...\n");
}

void task_three() {
    printf("[TASK THREE] Running...\n");
}

void task_four() {
    printf("[TASK FOUR] Running...\n");
}

void task_five() {
    printf("[TASK FIVE] Running...\n");
}

int main() {
    int task_schedule[MAX_TASKS];
    int i;

    // Initialize task schedule to all zeroes
    for (i = 0; i < MAX_TASKS; i++) {
        task_schedule[i] = 0;
    }

    // Generate random task schedule
    srand(time(NULL));
    for (i = 0; i < MAX_TASKS; i++) {
        int rand_task = rand() % MAX_TASKS;
        while (task_schedule[rand_task] != 0) {
            rand_task = (rand_task + 1) % MAX_TASKS;
        }
        task_schedule[rand_task] = i + 1;
    }

    // Print paranoid message
    printf("*** WARNING ***\n");
    printf("TASK SCHEDULED:\n");
    for (i = 0; i < MAX_TASKS; i++) {
        printf("Task %d: %d\n", i+1, task_schedule[i]);
    }
    printf("DO NOT TRUST ANYONE\n");

    // Run tasks in scheduled order
    for (i = 0; i < MAX_TASKS; i++) {
        int task_num = task_schedule[i];
        switch (task_num) {
            case 1:
                task_one();
                break;
            case 2:
                task_two();
                break;
            case 3:
                task_three();
                break;
            case 4:
                task_four();
                break;
            case 5:
                task_five();
                break;
            default:
                break;
        }
    }

    return 0;
}