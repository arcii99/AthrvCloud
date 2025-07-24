//FormAI DATASET v1.0 Category: Task Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TASK_NUM 5

typedef struct {
    int task_id;
    int duration;
} Task;

void execute_task(Task task) {
    printf("Task %d started\n", task.task_id);
    sleep(task.duration);
    printf("Task %d completed\n", task.task_id);
}

int main() {
    Task tasks[TASK_NUM] = {{1, 3}, {2, 5}, {3, 10}, {4, 2}, {5, 7}};

    printf("Welcome to the Cheerful Task Scheduler!\n");
    printf("We have %d tasks ready to go!\n", TASK_NUM);

    srand(time(NULL));
    int i, j;
    Task temp;
    for(i = 0; i < TASK_NUM; i++) {
        j = rand() % TASK_NUM;
        temp = tasks[i];
        tasks[i] = tasks[j];
        tasks[j] = temp;
    }

    printf("The order of tasks has been randomized!\n\n");

    int total_duration = 0;
    for(i = 0; i < TASK_NUM; i++) {
        total_duration += tasks[i].duration;
    }

    printf("Starting Task Scheduler...\n");
    printf("Estimated Time Remaining: %d seconds\n\n", total_duration);

    for(i = 0; i < TASK_NUM; i++) {
        execute_task(tasks[i]);
        total_duration -= tasks[i].duration;
        printf("Estimated Time Remaining: %d seconds\n\n", total_duration);
    }

    printf("All tasks have been completed!\n");
    printf("Thank you for using the Cheerful Task Scheduler!\n");

    return 0;
}