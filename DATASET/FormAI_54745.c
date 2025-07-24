//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Function to calculate CRAM usage in bytes
long long int getCramUsageInBytes() {
    FILE* file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: failed to read /proc/meminfo.\n");
        exit(EXIT_FAILURE);
    }

    char line[256];
    long long int totalCram = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Compressed") != NULL) {
            long long int value;
            sscanf(line, "Compressed: %lld", &value);
            // Convert to bytes
            totalCram += value * 1000;
        } else if (strstr(line, "SwapTotal") != NULL) {
            long long int value;
            sscanf(line, "SwapTotal: %lld", &value);
            // Convert to bytes
            totalCram += value * 1024;
        }
    }

    fclose(file);
    return totalCram;
}

int main() {
    while (1) {
        long long int cramUsage = getCramUsageInBytes();
        printf("CRAM Usage: %lld bytes\n", cramUsage);
        sleep(1);
    }
    return 0;
}