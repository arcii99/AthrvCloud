//FormAI DATASET v1.0 Category: System administration ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // fork a child process
    pid = fork();

    if (pid < 0) {  // error occurred
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (pid == 0) {  // child process
        printf("Child process running...\n");

        // set up system call to run desired command
        char *args[] = {"ls", "-l", NULL};
        execvp(args[0], args);

        printf("Child process finished executing system call\n");
        exit(0);  // exit child process
    } else {  // parent process
        wait(NULL);  // wait for child to complete

        printf("Parent process running...\n");
        printf("Child process finished executing system call\n");
    }

    return 0;
}