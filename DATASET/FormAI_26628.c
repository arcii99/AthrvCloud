//FormAI DATASET v1.0 Category: Task Scheduler ; Style: imaginative
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

int counter = 0;

void task1() {
    printf("Task 1 has been executed\n");
    counter++;
}

void task2() {
    printf("Task 2 has been executed\n");
    counter++;
}

void task3() {
    printf("Task 3 has been executed\n");
    counter++;
}

void alarm_handler(int signum) {
    switch(counter) {
        case 0:
            task1();
            break;
        case 1:
            task2();
            break;
        case 2:
            task3();
            break;
        default:
            printf("All tasks have been executed\n");
            exit(0);
    }

    alarm(10);
}

int main() {
    signal(SIGALRM, alarm_handler);
    alarm(10);

    while(1) {
        printf("Waiting for task to be executed...\n");
        sleep(1);
    }

    return 0;
}