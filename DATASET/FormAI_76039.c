//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// This function extracts the current memory usage (in kB) from the /proc/self/status file
double get_current_memory_usage() {
    FILE* file = fopen("/proc/self/status", "r");

    char buffer[BUFFER_SIZE];
    double memory_usage = -1;

    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (strncmp(buffer, "VmRSS:", 6) == 0) {
            char* bytes = strtok(buffer, " "); // Get the first token (label)
            bytes = strtok(NULL, " "); // Get the second token (memory usage in bytes)

            memory_usage = atof(bytes) / 1000; // Convert bytes to kB
            break;
        }
    }

    fclose(file);

    return memory_usage;
}

int main() {
    printf("Starting the RAM usage monitor program...\n");
    printf("Press Ctrl+C to exit.\n");

    while (1) {
        double memory_usage = get_current_memory_usage();
        printf("Current memory usage: %.2lf kB\n", memory_usage);

        sleep(1);
    }

    return 0;
}