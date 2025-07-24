//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * This program monitors the usage of C RAM on a Linux system.
 * It displays the current usage in percentage and updates every
 * second until the user interrupts the program.
 */

int main() {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    float total, used, free, buff, cache, sreclaimable;
    int i = 0;

    while (1) {
        fp = fopen("/proc/meminfo", "r");
        if (fp == NULL) {
            perror("Error opening /proc/meminfo");
            exit(EXIT_FAILURE);
        }

        while ((read = getline(&line, &len, fp)) != -1) {
            if (sscanf(line, "MemTotal: %f kB", &total) == 1 ||
                sscanf(line, "MemFree: %f kB", &free) == 1 ||
                sscanf(line, "Buffers: %f kB", &buff) == 1 ||
                sscanf(line, "Cached: %f kB", &cache) == 1 ||
                sscanf(line, "SReclaimable: %f kB", &sreclaimable) == 1) {
                    used = total - free - buff - cache - sreclaimable;
            }
        }

        printf("\rC RAM Usage: %.2f%%", used / total * 100);

        fclose(fp);
        sleep(1);

        i++;
        if (i >= 10) { // Clear the console after displaying for 10 seconds
            system("clear");
            i = 0;
        }
    }

    return 0;
}