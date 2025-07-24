//FormAI DATASET v1.0 Category: System administration ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    printf("Welcome to the System Administration Program!\n");
    pid_t pid = fork(); // create a child process

    if (pid < 0) {
        printf("Error: Fork failed!\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) { // child process
        printf("Child process started with PID %d\n", getpid());
        printf("Executing 'ls -l' command\n");
        char *args[] = {"ls", "-l", NULL};
        execvp(args[0], args); // execute 'ls -l'
    }
    else { // parent process
        printf("Parent process started with PID %d\n", getpid());
        printf("Waiting for child process to complete...\n");
        wait(NULL); // wait for child process to complete
        printf("Child process has completed execution!\n");
    }

    printf("Exiting System Administration Program\n");
    return 0;
}