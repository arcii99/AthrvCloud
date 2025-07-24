//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main() {
    // Fetching system info
    struct sysinfo sys_info;
    if (sysinfo(&sys_info) != 0) {
        perror("sysinfo");
        exit(EXIT_FAILURE);
    }
    long long total_ram = sys_info.totalram;
    int ram_unit = 1024;
    double total_ram_gb = (double)total_ram / (double)(ram_unit * ram_unit * ram_unit);
    printf("Total RAM: %.2f GB\n", total_ram_gb);

    // Continuous monitoring the RAM usage
    double used_ram = 0, prev_used_ram = 0, used_ram_percentage = 0;
    while(1) {
        // Fetching current RAM usage
        struct sysinfo sys_info_curr;
        if (sysinfo(&sys_info_curr) != 0) {
            perror("sysinfo");
            exit(EXIT_FAILURE);
        }
        used_ram = ((double)total_ram - (double)sys_info_curr.freeram) / (double)(ram_unit * ram_unit * ram_unit);
        used_ram_percentage = (used_ram / total_ram_gb) * 100.0;

        // Printing RAM usage
        if(prev_used_ram != used_ram) {
            printf("Used RAM: %.2f GB (%.2f%%)\n", used_ram, used_ram_percentage);
            prev_used_ram = used_ram;
        }
        sleep(3);
    }
    return 0;
}