//FormAI DATASET v1.0 Category: System process viewer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 1024
#define MAX_LINE 2048

int main() {
    // Declare shell command and buffer to store output
    char command[MAX_LINE];
    char buffer[MAX_LINE];

    // Open pipe to shell command
    FILE* command_stream = popen("ps -ef", "r");

    // Print header
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
           "UID", "PID", "PPID", "C", "STIME", "TTY", "TIME");

    // Iterate through each line of output
    while (fgets(buffer, MAX_LINE, command_stream) != NULL) {
        int argc = 0;
        char* argv[MAX_ARGS];

        // Use strtok to parse output into separate strings
        argv[argc++] = strtok(buffer, " ");
        while ((argv[argc++] = strtok(NULL, " ")) != NULL && argc < MAX_ARGS) {}

        // Print only if output line is valid
        if (argc >= 8) {
            printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s",
                   argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
            for (int i = 7; i < argc; i++) {
                printf("%s ", argv[i]);
            }
            printf("\n");
        }
    }

    // Close pipe and return success
    pclose(command_stream);
    return 0;
}