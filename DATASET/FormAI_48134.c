//FormAI DATASET v1.0 Category: System administration ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {  // Error handling if fork fails
        printf("Fork failed\n");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {  // Parent process
        printf("Parent process with PID: %d\n",getpid());
        printf("Child process has been created with PID: %d\n", pid);
        
        // Wait for child process to finish
        wait(NULL);
        
        printf("Child process has finished execution\n");
        printf("Parent process has finished execution\n");
        exit(EXIT_SUCCESS);
    }
    
    if (pid == 0) {  // Child process
        printf("Child process with PID: %d\n", getpid());
        
        // Change directory to root directory
        chdir("/");
        
        // Close all open file descriptors
        for (int fd = sysconf(_SC_OPEN_MAX); fd >= 0; fd--) {
            close(fd);
        }
        
        // Open a new file descriptor for logging
        FILE *log_file = fopen("/var/log/my_program.log", "a");
        
        // Redirect stdout and stderr to log file
        dup2(fileno(log_file), STDOUT_FILENO);
        dup2(fileno(log_file), STDERR_FILENO);
        
        // Run program as usual
        printf("Executing program as usual\n");
        // Code for program execution
        
        fclose(log_file);
        exit(EXIT_SUCCESS);
    }

    return 0;
}