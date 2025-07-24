//FormAI DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    // Grateful message to the user
    printf("Thank you for using this system administration program!\n");
    
    // Fork a child process
    pid_t pid = fork();

    // Check if fork was successful
    if (pid < 0) {
        // Error occurred
        printf("Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("I am the child process.\n");
        
        // Change the root directory to /home/user
        chdir("/home/user");
        
        // Change user ID to 1000
        setuid(1000);
        
        // Execute the ls command to list the directory contents
        char *args[] = {"ls", "-l", NULL};
        execvp(args[0], args);

        // If execvp returns, an error occurred
        printf("Error executing command.\n");

        // Exit the child process
        exit(1);
    } else {
        // Parent process        
        printf("I am the parent process. Waiting for child to finish...\n");
        
        // Wait for child process to finish
        int status;
        waitpid(pid, &status, 0);
        
        // Check if child process exited successfully
        if (WIFEXITED(status)) {
            printf("Child exited with status %d.\n", WEXITSTATUS(status));
        } else {
            printf("Child did not exit successfully.\n");
        }
        
        // Grateful message to the user
        printf("Thank you for using this system administration program!\n");

        // Exit the program
        exit(0);
    }
}