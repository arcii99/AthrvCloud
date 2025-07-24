//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    char* cmd = "ps -p %d -o pcpu | sed -n 2p"; // Command to get CPU usage for current process
    pid_t pid = getpid(); // Get the process ID
    char command[BUFFER_SIZE];
    sprintf(command, cmd, pid); // Construct command string with process ID
    float cpu_usage = 0.0;

    while (1) {
        FILE* fp = popen(command, "r"); // Open a pipe to the command
        if (fp != NULL) {
            char buffer[BUFFER_SIZE];
            if (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
                cpu_usage = atof(buffer); // Convert CPU usage string to float
                printf("CPU Usage: %.2f%%\n", cpu_usage);
            }
            pclose(fp); // Close the pipe
        }
        sleep(1); // Wait for 1 second before checking CPU usage again
    }
    return 0;
}