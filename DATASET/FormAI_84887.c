//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int main() {
    printf("Welcome to the C RAM usage monitor program!\n\n");

    struct sysinfo sys_info;

    while(1) {
        sysinfo(&sys_info);

        unsigned long long total_ram = sys_info.totalram * sys_info.mem_unit;
        unsigned long long free_ram = sys_info.freeram * sys_info.mem_unit;
        unsigned long long used_ram = total_ram - free_ram;

        printf("Total RAM: %-10llu MB Used RAM: %-10llu MB Free RAM: %-10llu MB\r", total_ram / (1024 * 1024), used_ram / (1024 * 1024), free_ram / (1024 * 1024));
        fflush(stdout);

        sleep(1);
    }

    return 0;
}