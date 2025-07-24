//FormAI DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include <stdio.h>

void task1() {
    printf("Task 1 is executing.\n");
}

void task2() {
    printf("Task 2 is executing.\n");
}

void task3() {
    printf("Task 3 is executing.\n");
}

int main() {
    // Schedule tasks to run at specific times
    int time1 = 5;
    int time2 = 10;
    int time3 = 15;

    int currentTime = 0;
    while (1) {
        // Check if it's time to execute tasks
        if (currentTime == time1) {
            task1();
        }
        if (currentTime == time2) {
            task2();
        }
        if (currentTime == time3) {
            task3();
        }

        // Increment current time
        currentTime++;

        // Reset current time when it reaches 20
        if (currentTime == 20) {
            currentTime = 0;
        }
    }

    return 0;
}