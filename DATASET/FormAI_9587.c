//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define NUM_CORES 4

/* Function to extract CPU usage for each core */
float get_core_usage(char *line) {
    char *token;
    float usage;
    int i = 0;
    token = strtok(line, " "); // Separate string based on delimiter " "
    while (token != NULL) {
        if (i == 0) {
            usage = strtof(token, NULL); // Convert string to float
        }
        if (i == 2) {
            usage += strtof(token, NULL); // Add %iowait, which is second item in line
        }
        token = strtok(NULL, " ");
        i++;
    }
    return usage;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    float core_usage[NUM_CORES];
    float total_usage = 0.0;
    int i;

    /* Open stat file for reading CPU usage information */
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    /* Read and extract CPU usage information */
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        if (strncmp(line, "cpu", 3) == 0) { // Lines that start with "cpu" contain CPU usage information
            /* Extract first four cores usage */
            if (line[3] >= '0' && line[3] <= '3') {
                i = line[3] - '0';
                core_usage[i] = get_core_usage(line + 5);
            }
            /* Extract total CPU usage */
            else if (strncmp(line, "cpu ", 4) == 0) {
                total_usage = get_core_usage(line + 5);
            }
        }
    }
    fclose(fp);

    /* Print CPU usage information */
    printf("CPU Usage:\n");
    for (i = 0; i < NUM_CORES; i++) {
        printf("Core %d: %.2f%%\n", i, core_usage[i]);
    }
    printf("Total: %.2f%%\n", total_usage);

    return 0;
}