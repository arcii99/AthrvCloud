//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    int sleep_time = 5; // sleep for 5 seconds before checking RAM usage again

    while(1) {
        sysinfo(&info);
        long long total_ram = info.totalram * info.mem_unit;
        long long free_ram = info.freeram * info.mem_unit;
        long long used_ram = total_ram - free_ram;
        
        // calculate RAM usage percentage to 2 decimal places
        double ram_usage = ((double) used_ram / total_ram) * 100.0;
        printf("Total RAM: %lld bytes\n", total_ram);
        printf("Free RAM: %lld bytes\n", free_ram);
        printf("Used RAM: %lld bytes\n", used_ram);
        printf("RAM Usage: %.2lf%%\n", ram_usage);
       
        sleep(sleep_time);
    }

    return 0;
}