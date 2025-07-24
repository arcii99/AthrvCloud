//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 1024

void printUsage() {
    fprintf(stderr, "Usage: cramu [-h]\n");
}

void printHelp() {
    fprintf(stderr, "C RAM Usage Monitor\n\n");
    printUsage();
    fprintf(stderr, "\nOptions:\n");
    fprintf(stderr, " -h         display this help message\n");
}

int main(int argc, char *argv[]) {
    int opt;

    while ((opt = getopt(argc, argv, "h")) != -1) {
        switch (opt) {
            case 'h':
                printHelp();
                return 0;
            default:
                printUsage();
                return 1;
        }
    }

    FILE *fp;
    char buffer[MAX_SIZE];
    char *token;
    int total, used, free, shared, buff, cache, available;
    
    while (1) {
        fp = fopen("/proc/meminfo", "r");
        if (fp == NULL) {
            fprintf(stderr, "Error opening file: /proc/meminfo\n");
            return 1;
        }

        // Get total memory
        fgets(buffer, MAX_SIZE, fp);
        token = strtok(buffer, " ");
        token = strtok(NULL, " ");
        total = atoi(token);
        fgets(buffer, MAX_SIZE, fp); // Skip second line

        // Get free memory
        fgets(buffer, MAX_SIZE, fp);
        token = strtok(buffer, " ");
        token = strtok(NULL, " ");
        free = atoi(token);
        fgets(buffer, MAX_SIZE, fp); // Skip third line

        // Get used memory
        fgets(buffer, MAX_SIZE, fp);
        token = strtok(buffer, " ");
        token = strtok(NULL, " ");
        used = total - atoi(token);
        snprintf(buffer, MAX_SIZE, "Used: %dKB / Total: %dKB\n", used, total);
        fprintf(stdout, "%s", buffer);

        fclose(fp);
        sleep(1); // Wait for one second
    }
    
    return 0;
}