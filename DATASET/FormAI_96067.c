//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Global variables
const int MAX_RAM_SIZE = 1024 * 1024 * 1024; // 1 GB
int total_ram_used = 0;
int max_ram_used = 0;

// Function to get RAM usage of current process
int get_ram_usage() {
    FILE* fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Couldn't open /proc/self/status file.\n");
        exit(EXIT_FAILURE);
    }

    char line[128];
    while (fgets(line, 128, fp) != NULL) {
        if (strncmp(line, "VmRSS:", 6) == 0) {
            int ram_size = atoi(&line[7]);
            return ram_size * 1024; // Converting from KB to bytes
        }
    }

    fclose(fp);

    return 0;
}

// Function to display RAM usage
void display_ram_usage() {
    int ram_used = get_ram_usage();
    if (ram_used > max_ram_used) {
        max_ram_used = ram_used;
    }

    total_ram_used += ram_used;

    printf("Current RAM usage: %d bytes\n", ram_used);
    printf("Total RAM used so far: %d bytes\n", total_ram_used);
    printf("Max RAM used: %d bytes\n", max_ram_used);
}

int main() {
    while (total_ram_used < MAX_RAM_SIZE) {
        display_ram_usage();
        sleep(1);
    }

    printf("Memory limit reached. Exiting program...\n");

    return 0;
}