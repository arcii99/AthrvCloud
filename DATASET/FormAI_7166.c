//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <string.h>

int main() {
    struct sysinfo mem_info;
    memset(&mem_info, 0, sizeof(struct sysinfo));

    while (1) {
        if (sysinfo(&mem_info) != 0) {
            printf("Error: Couldn't retrieve system info.\n");
            exit(1);
        }

        long long total_ram = (mem_info.totalram * mem_info.mem_unit) / (1024 * 1024);
        long long free_ram = (mem_info.freeram * mem_info.mem_unit) / (1024 * 1024);

        printf("\rTotal RAM: %lld MB\tFree RAM: %lld MB\tRAM used: %lld MB", 
               total_ram, free_ram, total_ram - free_ram);

        fflush(stdout);
        sleep(1);
    }

    return 0;
}