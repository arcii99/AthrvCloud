//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid = fork(); // Create a child process
    if (pid == 0) { // Child process
        while (1) {
            printf("Child process running...\n");
            sleep(1); // Sleep for 1 second
        }
    } else if (pid > 0) { // Parent process
        clock_t start_time = clock(); // Get start time
        while (1) {
            clock_t current_time = clock(); // Get current time
            double elapsed_time = (double) (current_time - start_time) / CLOCKS_PER_SEC;
            
            // Print CPU usage every 5 seconds
            if ((int) elapsed_time % 5 == 0) {
                int status;
                pid_t result = waitpid(pid, &status, WNOHANG);
                if (result == 0) { // Child process still running
                    printf("CPU Usage: %.2f%%\n", (double) (elapsed_time * 100) / 5);
                } else if (result == pid) { // Child process has terminated
                    printf("Child process terminated.\n");
                    exit(0); // Terminate parent process
                }
            }
            
            // Sleep for 1 second
            sleep(1);
        }
    } else { // Error handling
        perror("fork");
        exit(1);
    }
    
    return 0;
}