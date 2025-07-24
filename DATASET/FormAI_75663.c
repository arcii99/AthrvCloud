//FormAI DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

void task1(void) {
    printf("Task 1 is being executed.\n");
}

void task2(void) {
    printf("Task 2 is being executed.\n");
}

void task3(void) {
    printf("Task 3 is being executed.\n");
}

int main() {
    int task1Interval, task2Interval, task3Interval;
    int time = 0;

    printf("Enter time interval for Task 1: ");
    scanf("%d", &task1Interval);

    printf("Enter time interval for Task 2: ");
    scanf("%d", &task2Interval);

    printf("Enter time interval for Task 3: ");
    scanf("%d", &task3Interval);

    while (1) {
        if (time % task1Interval == 0) {
            task1();
        }
        if (time % task2Interval == 0) {
            task2();
        }
        if (time % task3Interval == 0) {
            task3();
        }

        time++;
    }

    return 0;
}
