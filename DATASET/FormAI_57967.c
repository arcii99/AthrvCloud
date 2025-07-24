//FormAI DATASET v1.0 Category: System administration ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t child_pid;
    char *hostname = "google.com"; // change the hostname as per your requirements
    
    // fork a child process
    child_pid = fork();
    
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // child process
        printf("Checking if %s is up...\n", hostname);
        execlp("ping", "ping", "-c", "5", hostname, NULL);
        
        // if the code reaches here, that means execlp has failed
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        // parent process
        int status;
        waitpid(child_pid, &status, 0);
        
        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            if (exit_status == 0) {
                printf("%s is up and running!\n", hostname);
            } else {
                printf("%s seems to be down.\n", hostname);
            }
        } else {
            printf("Error: child process terminated abnormally.\n");
        }
    }
    
    return 0;
}