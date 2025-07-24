//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_meminfo(long* total_memory, long* free_memory) {
    FILE *fp = fopen("/proc/meminfo", "r");
    char buffer[BUFFER_SIZE];

    if (!fp) {
        fprintf(stderr, "Failed to open /proc/meminfo file.\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, BUFFER_SIZE);

    while (fgets(buffer, BUFFER_SIZE, fp)) {
        if (sscanf(buffer, "MemTotal: %ld", total_memory) == 1) continue;
        if (sscanf(buffer, "MemFree: %ld", free_memory) == 1) break;
    }

    fclose(fp);
}

int get_ram_percentage() {
    long total_memory, free_memory;

    parse_meminfo(&total_memory, &free_memory);

    if (total_memory == 0) {
        fprintf(stderr, "Failed to get total memory.\n");
        exit(EXIT_FAILURE);
    }

    return (int)((total_memory - free_memory) * 100 / total_memory);
}

int main() {
    int ram_percentage = get_ram_percentage();

    printf("RAM usage: %d%%\n", ram_percentage);

    return 0;
}