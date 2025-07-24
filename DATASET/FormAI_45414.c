//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    FILE *fp;
    char buffer[100];
    int total, free, used;

    printf("Live C RAM Usage Monitor\n\n");

    while (1) {
        fp = fopen("/proc/meminfo", "r");
        if (fp == NULL)
            exit(EXIT_FAILURE);

        // Parse the contents of /proc/meminfo
        while (fgets(buffer, sizeof(buffer), fp)) {
            if (sscanf(buffer, "MemTotal: %d", &total) == 1)
                continue;
            if (sscanf(buffer, "MemFree: %d", &free) == 1)
                continue;
        }

        fclose(fp);

        // Calculate used memory
        used = total - free;

        printf("Total Memory: %d kB\n", total);
        printf("Free Memory: %d kB\n", free);
        printf("Used Memory: %d kB\n", used);
        printf("--------------------------------\n");

        sleep(1); // Sleep for 1 second
    }

    return 0;
}