//FormAI DATASET v1.0 Category: System administration ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    int pid = fork();
    if (pid == 0) { // first child process
        printf("Executing command: ls\n");
        char *args[] = {"ls", NULL};
        execvp(args[0], args);
    } else { // parent process
        int status;
        waitpid(pid, &status, 0);
        printf("\nls command exited with status: %d\n", status);
        pid = fork();
        if (pid == 0) { // second child process
            printf("\nExecuting command: touch file1.txt\n");
            char *args[] = {"touch", "file1.txt", NULL};
            execvp(args[0], args);
        } else { // parent process
            waitpid(pid, &status, 0);
            printf("\ntouch command exited with status: %d\n", status);
            pid = fork();
            if (pid == 0) { // third child process
                printf("\nExecuting command: echo 'Hello, World!' > file1.txt\n");
                char *args[] = {"sh", "-c", "echo 'Hello, World!' > file1.txt", NULL};
                execvp(args[0], args);
            } else { // parent process
                waitpid(pid, &status, 0);
                printf("\necho command exited with status: %d\n", status);
                pid = fork();
                if (pid == 0) { // fourth child process
                    printf("\nExecuting command: cat file1.txt\n");
                    char *args[] = {"cat", "file1.txt", NULL};
                    execvp(args[0], args);
                } else { // parent process
                    waitpid(pid, &status, 0);
                    printf("\ncat command exited with status: %d\n", status);
                    printf("\nDone!\n");
                    exit(0);
                }
            }
        }
    }
}