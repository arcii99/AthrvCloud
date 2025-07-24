//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: dynamic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

    while (1) {
        // Get system memory information
        FILE *meminfo = fopen("/proc/meminfo", "r");
        if (meminfo == NULL) {
            perror("Error opening /proc/meminfo");
            exit(EXIT_FAILURE);
        }

        char line[256];
        long total_mem = 0, free_mem = 0, used_mem = 0;
        while (fgets(line, sizeof(line), meminfo)) {
            if (strncmp(line, "MemTotal:", 9) == 0) {
                char *ptr = line + 9;
                while (*ptr == ' ') ptr++;
                total_mem = strtol(ptr, NULL, 10) * 1024;
            }
            else if (strncmp(line, "MemFree:", 8) == 0) {
                char *ptr = line + 8;
                while (*ptr == ' ') ptr++;
                free_mem = strtol(ptr, NULL, 10) * 1024;
            }
            else if (strncmp(line, "Buffers:", 8) == 0) {
                char *ptr = line + 8;
                while (*ptr == ' ') ptr++;
                free_mem += strtol(ptr, NULL, 10) * 1024;
            }
            else if (strncmp(line, "Cached:", 7) == 0) {
                char *ptr = line + 7;
                while (*ptr == ' ') ptr++;
                free_mem += strtol(ptr, NULL, 10) * 1024;
            }
        }
        fclose(meminfo);

        used_mem = total_mem - free_mem;
        float used_perc = (float)used_mem / (float)total_mem * 100.0;

        // Output memory usage percentage
        printf("\rMemory usage: %.1f%%", used_perc);
        fflush(stdout);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}