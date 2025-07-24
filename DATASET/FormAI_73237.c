//FormAI DATASET v1.0 Category: Task Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int task1() {
    printf("Task 1 - Hello World!\n");
    sleep(2); // wait for 2 seconds
    return 0;
}

int task2() {
    printf("Task 2 - Random Number Generator\n");
    srand(time(NULL)); // seed the random number generator with current time
    for (int i = 0; i < 5; i++) {
        printf("%d ", rand() % 100); // generate a random number between 0-99
    }
    printf("\n");
    return 0;
}

int task3() {
    printf("Task 3 - Counting\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i); // print numbers 1 to 5
    }
    printf("\n");
    return 0;
}

int main() {
    int time_remaining = 10; // total time for scheduler in seconds
    int interval1 = 3, interval2 = 2, interval3 = 1; // intervals in seconds for each task
    int timer1 = interval1, timer2 = interval2, timer3 = interval3; // timers for each task
    
    while (time_remaining > 0) {
        if (timer1 == 0) {
            task1(); // execute task 1 if interval has passed
            timer1 = interval1; // reset timer
        }
        if (timer2 == 0) {
            task2(); // execute task 2 if interval has passed
            timer2 = interval2; // reset timer
        }
        if (timer3 == 0) {
            task3(); // execute task 3 if interval has passed
            timer3 = interval3; // reset timer
        }
        printf("Time Remaining: %d seconds\n", time_remaining);
        sleep(1); // wait for 1 second
        time_remaining--; // decrement total time remaining
        timer1--; // decrement task 1 timer
        timer2--; // decrement task 2 timer
        timer3--; // decrement task 3 timer
    }
    
    printf("Scheduler Completed!\n");
    return 0;
}