//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* Task Definition */
typedef struct {
    char* name;
    int interval;
    time_t last_run;
    void (*task_function)(void);
} task_t;

/* Sample Task Functions */
void task1() {
    printf("Task 1 Running...\n");
}

void task2() {
    printf("Task 2 Running...\n");
}

void task3() {
    printf("Task 3 Running...\n");
}

/* Main Scheduler Loop */
int main() {
    srand(time(NULL)); // Seed RNG for Task Intervals

    /* Define and Initialize Tasks */
    task_t tasks[] = {
        {"Task 1", rand() % 5 + 1, (time_t)0, &task1},
        {"Task 2", rand() % 10 + 1, (time_t)0, &task2},
        {"Task 3", rand() % 15 + 1, (time_t)0, &task3}
    };
    int num_tasks = sizeof(tasks) / sizeof(task_t);

    printf("Task Scheduler Started.\n");

    while (1) {
        for (int i = 0; i < num_tasks; i++) {
            // Check if Interval has Elapsed
            time_t now = time(NULL);
            double seconds_passed = difftime(now, tasks[i].last_run);
            if (seconds_passed >= tasks[i].interval) {
                // Execute Task and Update Last Run Time
                printf("%s Executing...\n", tasks[i].name);
                tasks[i].task_function();
                tasks[i].last_run = now;
            }
        }
        usleep(1000000); // Sleep for 1 Second
    }

    return 0;
}