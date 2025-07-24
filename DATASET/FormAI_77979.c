//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// This program uses the proc file system to obtain CPU usage information

// Struct to hold CPU usage statistics
typedef struct {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
} CpuUsage;

// Function to read the /proc/stat file and obtain CPU usage statistics
CpuUsage getCpuUsage() {
    CpuUsage usage = {0};
    char statFilePath[] = "/proc/stat";
    char buffer[256];

    // Open /proc/stat file and read first line
    FILE* statFile = fopen(statFilePath, "r");
    if (statFile == NULL) {
        printf("Error: Could not open /proc/stat file.\n");
        exit(EXIT_FAILURE);
    }
    if (fgets(buffer, sizeof(buffer), statFile) == NULL) {
        printf("Error: Could not read /proc/stat file.\n");
        exit(EXIT_FAILURE);
    }

    // Parse CPU usage statistics from first line
    char* stats = strtok(buffer, " ");
    for (int i = 0; i < 7; i++) {
        stats = strtok(NULL, " ");
        switch (i) {
            case 0:
                usage.user = strtoull(stats, NULL, 10);
                break;
            case 1:
                usage.nice = strtoull(stats, NULL, 10);
                break;
            case 2:
                usage.system = strtoull(stats, NULL, 10);
                break;
            case 3:
                usage.idle = strtoull(stats, NULL, 10);
                break;
            case 4:
                usage.iowait = strtoull(stats, NULL, 10);
                break;
            case 5:
                usage.irq = strtoull(stats, NULL, 10);
                break;
            case 6:
                usage.softirq = strtoull(stats, NULL, 10);
                break;
        }
    }

    // Close /proc/stat file
    fclose(statFile);

    return usage;
}

int main() {
    // Set interval in seconds to obtain CPU usage statistics
    int interval = 1;

    // Variables to store CPU usage statistics for calculation of usage percentage
    CpuUsage initialUsage = getCpuUsage();
    CpuUsage currentUsage = {0};

    // Infinite loop to periodically obtain and display CPU usage percentage
    while (1) {
        // Wait for the specified interval before obtaining and displaying CPU usage percentage
        sleep(interval);

        // Obtain current CPU usage statistics
        currentUsage = getCpuUsage();

        // Calculate total CPU time and usage percentage
        unsigned long long totalIdle = currentUsage.idle - initialUsage.idle;
        unsigned long long totalNonIdle = (currentUsage.user + currentUsage.nice + currentUsage.system
            + currentUsage.iowait + currentUsage.irq + currentUsage.softirq) -
            (initialUsage.user + initialUsage.nice + initialUsage.system + initialUsage.iowait + initialUsage.irq + initialUsage.softirq);
        unsigned long long totalCpuTime = totalIdle + totalNonIdle;
        float usagePercentage = (float)totalNonIdle / totalCpuTime * 100;

        // Display CPU usage percentage
        printf("CPU usage: %.2f%\n", usagePercentage);
    }

    return 0;
}