//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main() {
    printf("Welcome to the CPU Usage Monitor!\n");

    while(1) {
        struct sysinfo info;
        if(sysinfo(&info) != 0) {
            printf("Error getting system information.\n");
            exit(EXIT_FAILURE);
        }

        unsigned long total_ram = info.totalram;
        unsigned long free_ram = info.freeram;
        unsigned long used_ram = total_ram - free_ram;
        double ram_percent_used = ((double)used_ram / total_ram) * 100;

        printf("\n--- CPU Usage ---\n");
        system("top -b -n1 | grep \"Cpu(s)\" | awk '{print $2 + $4}'");

        printf("\n--- Memory Usage ---\n");
        printf("Total RAM: %lu\n", total_ram);
        printf("Used RAM: %lu\n", used_ram);
        printf("Free RAM: %lu\n", free_ram);
        printf("Percentage of RAM used: %.2f%%\n", ram_percent_used);

        sleep(2);
    }

    return 0;
}