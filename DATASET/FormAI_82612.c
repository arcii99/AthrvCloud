//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MB 1048576    // Conversion factor from bytes to megabytes

// Function to get the current RAM usage of the system
double get_ram_usage()
{
    struct sysinfo mem_info;
    sysinfo(&mem_info);
    long total_mem = mem_info.totalram;
    long free_mem = mem_info.freeram;
    double used_mem = (total_mem - free_mem);
    double ram_usage = used_mem / (double)total_mem * 100.0;
    return ram_usage;
}

int main()
{
    printf("Starting C RAM Usage Monitor...\n");
    printf("--------------------------------\n");

    // Continuously print the RAM usage
    while (1)
    {
        printf("RAM usage: %.2f MB (%.1f%%)\n", get_ram_usage() / MB, get_ram_usage());
        sleep(1);    // Wait 1 second before getting RAM usage again
    }

    return 0;    // End program
}