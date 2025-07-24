//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    int delay = 3; // Seconds between RAM usage checks
    long int max_ram = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE); // Total RAM
    long int available_ram, used_ram, prev_used_ram = 0;
    int percent_ram_used;

    while(1) { // Loop indefinitely
        FILE* fp = fopen("/proc/meminfo", "r");
        if(fp == NULL) {
            printf("Error: Failed to open /proc/meminfo\n");
            exit(1);
        }

        // Read total available RAM
        char meminfo_line[256];
        fgets(meminfo_line, 256, fp);
        sscanf(meminfo_line, "MemAvailable: %ld", &available_ram);

        fclose(fp);

        used_ram = max_ram - available_ram;
        percent_ram_used = used_ram * 100 / max_ram;

        printf("RAM usage: %ld/%ld MB (%d%%)\n", used_ram/1024/1024, max_ram/1024/1024, percent_ram_used);

        if (used_ram > prev_used_ram) {
            printf("RAM usage increased!\n");
        }
        else if (used_ram < prev_used_ram) {
            printf("RAM usage decreased!\n");
        }
        prev_used_ram = used_ram;

        sleep(delay);
    }

    return 0;
}