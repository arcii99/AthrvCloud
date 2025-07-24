//FormAI DATASET v1.0 Category: System administration ; Style: ultraprecise
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    
    pid_t pid;
    int status;
    
    // Check if user has superuser privileges
    if(getuid() != 0) {
        printf("You do not have superuser privileges. Please run the program as root.\n");
        return 1;
    }
    
    // Fork a child process
    pid = fork();
    
    // Check if fork was successful
    if(pid < 0) {
        printf("Fork failed. Please try again.\n");
        return 1;
    }
    
    // Check if this is the child process
    if(pid == 0) {
        
        // Execute the desired command
        printf("Executing the 'ls' command...\n");
        execl("/bin/ls", "ls", "-l", (char *)NULL);
        
        // Exit the child process
        _exit(0);
        
    } else {
        
        // Wait for the child process to terminate
        printf("Waiting for the 'ls' command to finish...\n");
        waitpid(pid, &status, 0);
        
        // Check if the child process terminated successfully
        if(WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            printf("The 'ls' command completed successfully.\n");
        } else {
            printf("The 'ls' command failed to complete.\n");
        }
        
    }
    
    return 0;
}