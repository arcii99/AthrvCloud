//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    FILE *fp;
    char buffer[1024], *ptr;
    int total_mem, used_mem, free_mem;
    float mem_used_pct;

    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        printf("Error opening /proc/meminfo.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (strstr(buffer, "MemTotal:") != NULL) {
            ptr = buffer + strlen("MemTotal:");
            total_mem = strtol(ptr, &ptr, 10) * 1024;
        }
        else if (strstr(buffer, "MemFree:") != NULL) {
            ptr = buffer + strlen("MemFree:");
            free_mem = strtol(ptr, &ptr, 10) * 1024;
        }
        else if (strstr(buffer, "Buffers:") != NULL || strstr(buffer, "Cached:") != NULL) {
            ptr = buffer + strcspn(buffer, "0123456789");
            used_mem += strtol(ptr, &ptr, 10) * 1024;
        }
    }

    fclose(fp);

    used_mem = total_mem - free_mem;

    mem_used_pct = ((float) used_mem / (float) total_mem) * 100.0;

    printf("Total memory: %d KB\n", total_mem / 1024);
    printf("Used memory: %d KB\n", used_mem / 1024);
    printf("Free memory: %d KB\n", free_mem / 1024);
    printf("Memory usage: %.2f%%\n", mem_used_pct);

    return 0;
}