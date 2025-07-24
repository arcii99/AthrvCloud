//FormAI DATASET v1.0 Category: System administration ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if (pid < 0) {
        perror("Fork Failed");
        exit(1);
    } 
    else if (pid == 0) {
        char *args[] = {"ls", "-la", NULL};
        int ret = execvp(args[0], args);
        if (ret < 0) {
            perror("Execvp Failed");
            exit(1);
        }
    } 
    else {
        wait(NULL);
        printf("\nChild Complete\n");
        system("cd /home/user/testdir && rm -rf *"); // Example System Administration task
        printf("Directory Cleared\n");
    }
    return 0;
}