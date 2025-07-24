//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    double total_mem, free_mem, used_mem, buffer_mem, cached_mem, shared_mem, s_reclaimable;
    FILE* meminfo = fopen("/proc/meminfo", "r");
    if (meminfo != NULL)
    {
        fscanf(meminfo, "MemTotal: %lf kB\n", &total_mem);
        fscanf(meminfo, "MemFree: %lf kB\n", &free_mem);
        fscanf(meminfo, "Buffers: %lf kB\n", &buffer_mem);
        fscanf(meminfo, "Cached: %lf kB\n", &cached_mem);
        fscanf(meminfo, "Shmem: %lf kB\n", &shared_mem);
        fscanf(meminfo, "SReclaimable: %lf kB", &s_reclaimable);

        used_mem = total_mem - free_mem - buffer_mem - cached_mem - shared_mem + s_reclaimable;

        printf("Total memory: %.2lf MB\n", total_mem/1024);
        printf("Used memory: %.2lf MB\n", used_mem/1024);
        printf("Free memory: %.2lf MB\n", free_mem/1024);

        double ram_utilization = used_mem / total_mem;
        if (ram_utilization > 0.8)
        {
            printf("Warning: RAM usage is high. Please close unnecessary programs.\n");
        }
    }
    else
    {
        printf("Error: could not read /proc/meminfo.\n");
    }
    return 0;
}