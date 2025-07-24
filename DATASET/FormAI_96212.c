//FormAI DATASET v1.0 Category: Funny ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("This program generates random numbers asynchronously!\n");

    // create two child processes
    pid_t pid1, pid2;
    pid1 = fork();

    if (pid1 == 0) {
        srand(time(NULL));
        while (1) {
            int num = rand() % 100;
            printf("Child1: %d\n", num);
            sleep(1);
        }
    }
    else {
        pid2 = fork();
        if (pid2 == 0) {
            srand(time(NULL));
            while (1) {
                int num = rand() % 100;
                printf("Child2: %d\n", num);
                sleep(2);
            }
        }
        else {
            while (1) {
                printf("Parent: Waiting for a child process to finish...\n");
                int status;
                wait(&status);
                printf("Parent: Child process finished.\n");
                pid_t new_pid;

                if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                    new_pid = fork();
                    if (new_pid == 0) {
                        srand(time(NULL));
                        while (1) {
                            int num = rand() % 100;
                            printf("Child3: %d\n", num);
                            sleep(3);
                        }
                    }
                }
                else {
                    printf("Parent: Child process failed.\n");
                    exit(1);
                }
            }
        }
    }

    return 0;
}