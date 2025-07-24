//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: light-weight
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int total_ram, free_ram, used_ram;
    char command[100];
    FILE *mem_info;

    while (1) {
        // Construct the command and open file
        sprintf(command, "cat /proc/meminfo | grep MemTotal && cat /proc/meminfo | grep MemFree");
        mem_info = popen(command, "r");

        // Read the memory info
        int mem_total_kb, mem_free_kb;
        fscanf(mem_info, "MemTotal: %d kB\nMemFree: %d kB\n", &mem_total_kb, &mem_free_kb);

        // Close file
        pclose(mem_info);

        // Calculate the memory usage
        total_ram = mem_total_kb / 1024;
        free_ram = mem_free_kb / 1024;
        used_ram = total_ram - free_ram;

        // Print the usage
        printf("=============================================\n");
        printf("Total RAM: %d MB\n", total_ram);
        printf("Used RAM: %d MB\n", used_ram);
        printf("Free RAM: %d MB\n", free_ram);
        printf("=============================================\n");

        // Wait for 5 seconds
        sleep(5);
    }

    return 0;
}