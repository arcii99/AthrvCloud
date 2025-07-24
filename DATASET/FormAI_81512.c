//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Create buffer to hold directory path input
    char directory[256];
    printf("Enter directory path: ");
    fgets(directory, 256, stdin);
    directory[strcspn(directory, "\n")] = 0; // Remove newline character at end of input

    // Create command to get directory disk space usage
    char command[256];
    strcpy(command, "du -hs ");
    strcat(command, directory);

    // Open pipe to execute command
    FILE *fp = popen(command, "r");
    if (!fp) {
        printf("Error: Failed to execute command.\n");
        return 1;
    }

    // Read output of command from pipe and print to console
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }

    // Close pipe and return success
    pclose(fp);
    return 0;
}