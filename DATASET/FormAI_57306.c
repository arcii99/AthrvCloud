//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#define MAX_LENGTH 256

uint64_t get_ram_usage() {
    char line[MAX_LENGTH];
    uint64_t ram_usage = 0;
    FILE* file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        printf("Error opening /proc/meminfo\n");
        exit(1);
    }
    while (fgets(line, MAX_LENGTH, file)) {
        if (strncmp(line, "MemAvailable:", 13) == 0) {
            sscanf(line + 13, "%lu", &ram_usage);
            break;
        }
    }
    fclose(file);
    return ram_usage;
}

int main() {
    while (1) {
        uint64_t ram_usage = get_ram_usage();
        printf("RAM usage: %lu kB\n", ram_usage);
        sleep(1);
    }
    return 0;
}