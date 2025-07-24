//FormAI DATASET v1.0 Category: Task Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// function to execute the task
void task1() {
    printf("Executing Task 1\n");
}

void task2() {
    printf("Executing Task 2\n");
}

// time in seconds for each task
const int TASK1_TIME = 5;
const int TASK2_TIME = 10;

int main() {
    pid_t pid;

    // create a child process
    pid = fork();

    if(pid < 0) {
        perror("fork");
        exit(1);
    }
    else if(pid == 0) {
        // child process

        while(1) {
            // execute task 1
            task1();
            sleep(TASK1_TIME);
        }
    }
    else {
        // parent process

        while(1) {
            // execute task 2
            task2();
            sleep(TASK2_TIME);
        }
    }

    return 0;
}