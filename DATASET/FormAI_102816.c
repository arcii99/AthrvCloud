//FormAI DATASET v1.0 Category: System administration ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2;
    int status1, status2;
    
    // create first child process
    pid1 = fork();
    
    if (pid1 < 0) { // error occurred
        printf("Fork failed\n");
        exit(1);
    } else if (pid1 == 0) { // child process
        printf("First child process: %d\n", getpid());
        
        // insert system administration task here
        
        printf("First child process finished.\n");
        exit(0);
    } else { // parent process
        // create second child process
        pid2 = fork();
        
        if (pid2 < 0) { // error occurred
            printf("Fork failed\n");
            exit(1);
        } else if (pid2 == 0) { // child process
            printf("Second child process: %d\n", getpid());
            
            // insert system administration task here
            
            printf("Second child process finished.\n");
            exit(0);
        } else { // parent process
            // wait for both child processes to finish
            waitpid(pid1, &status1, 0);
            waitpid(pid2, &status2, 0);
            
            printf("Parent process finished.\n");
            exit(0);
        }
    }
}