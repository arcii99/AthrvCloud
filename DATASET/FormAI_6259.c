//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MAX_LINE_LEN 80

int main() {
    // Open the file for writing
    FILE* fp = fopen("ram_usage.txt", "w+");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file\n");
        return 1;
    }

    // Loop indefinitely
    while (1) {
        // Get the system info
        struct sysinfo info;
        if (sysinfo(&info) != 0) {
            fprintf(stderr, "Failed to get system info\n");
            return 1;
        }

        // Calculate RAM usage
        double used_ram = (double) (info.totalram - info.freeram) / info.totalram;
        double used_swap = (double) info.totalswap ? (info.totalswap - info.freeswap) / info.totalswap : 0.0;

        char line[MAX_LINE_LEN];
        sprintf(line, "Used RAM: %f%%, Used Swap: %f%%\n", used_ram * 100.0, used_swap * 100.0);
        fputs(line, fp);

        // Sleep for 1 second
        sleep(1);
    }

    fclose(fp);
    return 0;
}