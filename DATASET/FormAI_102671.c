//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main()
{
    struct sysinfo si;
    unsigned long long total_ram, free_ram, used_ram;
    int percentage_used;

    while (1)
    {
        // Get system information
        if (sysinfo(&si) == -1)
        {
            printf("Error getting system info\n");
            exit(EXIT_FAILURE);
        }

        // Calculate RAM usage
        total_ram = si.totalram / 1024;
        free_ram = si.freeram / 1024;
        used_ram = total_ram - free_ram;
        percentage_used = (int)((double)used_ram / total_ram * 100);

        // Print results
        printf("Total RAM: %llu KB\n", total_ram);
        printf("Used RAM: %llu KB (%d%%)\n", used_ram, percentage_used);
        printf("Free RAM: %llu KB\n", free_ram);
        printf("--------------------\n");

        // Wait for 1 second
        sleep(1);
    }

    return 0;
}