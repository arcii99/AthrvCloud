//FormAI DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void (*task_fn)(void *);
    void *task_data;
    int interval;
    int runs;
} task_t;

void task1(void *data) {
    printf("This is task 1: %s\n", (char*)data);
}

void task2(void *data) {
    printf("This is task 2: %d\n", *(int*)data);
}

void task3(void *data) {
    printf("This is task 3: %f\n", *(float*)data);
}

void task4(void *data) {
    printf("This is task 4: %c\n", *(char*)data);
}

void schedule(task_t tasks[], int num_tasks) {
    int i;

    while (1) {
        for (i = 0; i < num_tasks; i++) {
            if (tasks[i].interval == 0) {
                (*tasks[i].task_fn)(tasks[i].task_data);
                tasks[i].runs--;

                if (tasks[i].runs == 0) {
                    tasks[i].interval = -1;
                }
            } else {
                tasks[i].interval--;
            }
        }
    }
}

int main() {
    task_t tasks[4];
    char str_task[] = "Hello, world!";
    int int_task = 123;
    float float_task = 3.14159265359;
    char char_task = 'A';

    tasks[0].task_fn = task1;
    tasks[0].task_data = &str_task;
    tasks[0].interval = 0;
    tasks[0].runs = 1;

    tasks[1].task_fn = task2;
    tasks[1].task_data = &int_task;
    tasks[1].interval = 2;
    tasks[1].runs = 5;

    tasks[2].task_fn = task3;
    tasks[2].task_data = &float_task;
    tasks[2].interval = 3;
    tasks[2].runs = 2;

    tasks[3].task_fn = task4;
    tasks[3].task_data = &char_task;
    tasks[3].interval = 0;
    tasks[3].runs = 3;

    schedule(tasks, 4);

    return 0;
}