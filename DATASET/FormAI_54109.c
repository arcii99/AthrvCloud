//FormAI DATASET v1.0 Category: Task Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TASKS 5
#define MIN_DELAY 1
#define MAX_DELAY 10

typedef struct {
    int id;
    int delay;
} Task;

void task1() {
    printf("Task 1 is running!\n");
}

void task2() {
    printf("Task 2 is running!\n");
}

void task3() {
    printf("Task 3 is running!\n");
}

void task4() {
    printf("Task 4 is running!\n");
}

void task5() {
    printf("Task 5 is running!\n");
}

int main() {
    Task tasks[NUM_TASKS];
    tasks[0] = (Task){1, 5};
    tasks[1] = (Task){2, 2};
    tasks[2] = (Task){3, 4};
    tasks[3] = (Task){4, 3};
    tasks[4] = (Task){5, 1};

    srand(time(NULL));

    while (1) {
        int i;
        for (i = 0; i < NUM_TASKS; i++) {
            if (tasks[i].delay == 0) {
                switch (tasks[i].id) {
                    case 1:
                        task1();
                        break;
                    case 2:
                        task2();
                        break;
                    case 3:
                        task3();
                        break;
                    case 4:
                        task4();
                        break;
                    case 5:
                        task5();
                        break;
                }
                tasks[i].delay = rand() % (MAX_DELAY - MIN_DELAY + 1) + MIN_DELAY;
            } else {
                tasks[i].delay--;
            }
        }
    }

    return 0;
}