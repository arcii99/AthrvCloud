//FormAI DATASET v1.0 Category: Task Scheduler ; Style: portable
#include <stdio.h>

void task1(void);
void task2(void);
void task3(void);

int main(void) {
    while (1) {
        task1();
        task2();
        task3();
    }
    return 0;
}

void task1(void) {
    static int count = 0;
    if (count == 0) {
        printf("Task 1 started.\n");
    }
    if (count == 5) {
        printf("Task 1 completed.\n");
        count = 0;
    }
    else {
        printf("Task 1 in progress.\n");
        count++;
    }
}

void task2(void) {
    static int count = 0;
    if (count == 0) {
        printf("Task 2 started.\n");
    }
    if (count == 10) {
        printf("Task 2 completed.\n");
        count = 0;
    }
    else {
        printf("Task 2 in progress.\n");
        count++;
    }
}

void task3(void) {
    static int count = 0;
    if (count == 0) {
        printf("Task 3 started.\n");
    }
    if (count == 20) {
        printf("Task 3 completed.\n");
        count = 0;
    }
    else {
        printf("Task 3 in progress.\n");
        count++;
    }
}