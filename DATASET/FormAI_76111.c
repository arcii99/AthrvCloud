//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define INTERVAL 5   // Update interval in seconds
#define MAX_LENGTH 50 // Maximum length of command

int main() {
    char command[MAX_LENGTH];
    int ram_usage;

    // Prompt user for command to monitor memory usage
    printf("Enter command to monitor memory usage: ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = 0; // Remove trailing newline character

    // Continuously monitor RAM usage
    while (1) {
        // Execute command and retrieve output
        FILE* fp = popen(command, "r");
        if (fp == NULL) {
            printf("Error executing command.\n");
            exit(1);
        }
        fscanf(fp, "%d", &ram_usage);
        pclose(fp);

        // Print RAM usage in MB
        printf("RAM usage: %d MB\n", ram_usage / 1024);

        // Wait for update interval
        sleep(INTERVAL);
    }

    return 0;
}