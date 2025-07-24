//FormAI DATASET v1.0 Category: System administration ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    int status;

    printf("Welcome to the System Administration program!\n\n");

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("Child process started. Executing 'ps -ef'.\n\n");
        execl("/bin/ps", "ps", "-ef", NULL);
        perror("exec failed");
        exit(1);
    } else {
        printf("Parent process waiting for child process to finish.\n\n");
        wait(&status);
        printf("\nChild process finished with status %d.\n", status);
    }

    printf("\nThank you for using the System Administration program!\n");

    return 0;
}