//FormAI DATASET v1.0 Category: Task Scheduler ; Style: beginner-friendly
#include <stdio.h>

void task1() {
    printf("Performing Task 1...\n");
}

void task2() {
    printf("Performing Task 2...\n");
}

void task3() {
    printf("Performing Task 3...\n");
}

int main() {
    int task_interval[] = {2, 5, 10};
    int task_counter[] = {0, 0, 0};
    int current_time = 0;

    while (1) {
        // Check if it's time to perform the first task
        if (current_time % task_interval[0] == 0 && task_counter[0] == 0) {
            task1();
            task_counter[0]++;
        }
        // Check if it's time to perform the second task
        if (current_time % task_interval[1] == 0 && task_counter[1] == 0) {
            task2();
            task_counter[1]++;
        }
        // Check if it's time to perform the third task
        if (current_time % task_interval[2] == 0 && task_counter[2] == 0) {
            task3();
            task_counter[2]++;
        }
        // Increment time counter and reset task counters
        if (current_time == 30) {
            break;
        } else if (current_time % 30 == 0) {
            current_time = 0;
            task_counter[0] = 0;
            task_counter[1] = 0;
            task_counter[2] = 0;
        }
        current_time++;
    }

    return 0;
}