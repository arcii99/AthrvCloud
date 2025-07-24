//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MB (1024 * 1024)

int main() {
    int total_mem = 0, free_mem = 0, used_mem = 0;
    float usage = 0.0;

    while (1) {
        FILE *fp_info = fopen("/proc/meminfo", "r");

        if (fp_info == NULL) {
            printf("Failed to read memory info.\n");
            exit(EXIT_FAILURE);
        }

        char buf[256];
        int mem_size;

        while (fgets(buf, sizeof(buf), fp_info) != NULL) {
            if (sscanf(buf, "MemTotal: %d kB", &mem_size) == 1) {
                total_mem = mem_size / 1024;
            } else if (sscanf(buf, "MemFree: %d kB", &mem_size) == 1) {
                free_mem = mem_size / 1024;
            }
        }

        fclose(fp_info);

        if (total_mem > 0 && free_mem > 0) {
            used_mem = total_mem - free_mem;
            usage = ((float) used_mem / (float) total_mem) * 100.0;

            // Output the RAM usage in a mathematical style
            printf("RAM usage: %.2f%% = %dMB / %dMB\n", usage, used_mem, total_mem);
        }

        sleep(5);  // Wait 5 seconds before checking again
    }

    return 0;
}