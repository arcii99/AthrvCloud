//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Thank you for choosing our RAM usage monitor!\n");

    while (1) {
        FILE* f = fopen("/proc/meminfo", "r");

        if (f == NULL) {
            printf("Oops, it looks like there was an error opening the memory info file.\n");
            continue;
        }

        int total_mem = 0;
        int free_mem = 0;
        int buffers = 0;
        int cached = 0;

        char line[256];

        while (fgets(line, sizeof(line), f)) {
            if (sscanf(line, "MemTotal: %d kB", &total_mem) == 1);
            else if (sscanf(line, "MemFree: %d kB", &free_mem) == 1);
            else if (sscanf(line, "Buffers: %d kB", &buffers) == 1);
            else if (sscanf(line, "Cached: %d kB", &cached) == 1);
        }

        fclose(f);

        int used_mem = total_mem - free_mem - buffers - cached;

        printf("Thank you for staying with us! Your RAM usage is: %d kB / %d kB\n", used_mem, total_mem);

        sleep(1);
    }

    return 0;
}