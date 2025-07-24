//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#define CONVERT_TO_MB(x) ((x)/1024)
#define CONVERT_TO_GB(x) ((x)/1024)/1024

int main() {
    unsigned long long total_ram;
    struct sysinfo info;
    int sleep_time = 1, counter = 0;

    sysinfo(&info);
    total_ram = info.totalram;

    while (1) {
        sysinfo(&info);

        unsigned long long free_ram = info.freeram;
        unsigned long long used_ram = total_ram - free_ram;
        unsigned long long percent_used = (used_ram * 100.0) / total_ram;

        printf("RAM Usage: %llu MB | Usage Percentage: %llu %%\n", CONVERT_TO_MB(used_ram), percent_used);

        counter++;
        if (counter % 5 == 0) {
            printf("Total RAM: %llu GB | Free RAM: %llu MB | Available RAM: %llu MB\n", CONVERT_TO_GB(total_ram),
                   CONVERT_TO_MB(free_ram), CONVERT_TO_MB(info.freeram + info.bufferram + info.sharedram));
        }

        sleep(sleep_time);
    }
    
    return 0;
}