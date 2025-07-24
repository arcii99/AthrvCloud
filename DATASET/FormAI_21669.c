//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    unsigned long long mem_total, mem_free, mem_used, mem_buffer, mem_cache, mem_sreclaim, mem_shmem;

    FILE *meminfo = fopen("/proc/meminfo", "r");

    if(meminfo == NULL)
    {
        printf("Error: failed to open /proc/meminfo\n");
        exit(EXIT_FAILURE);
    }

    while(fscanf(meminfo, " %*s %llu %*s\n"\
                  " %*s %llu %*s\n"\
                  " %*s %llu %*s\n"\
                  " %*s %*u %*s\n"\
                  " %*s %llu %*s\n"\
                  " %*s %llu %*s\n"\
                  " %*s %*u %*s\n", &mem_total, &mem_free, &mem_used, &mem_buffer, &mem_cache, &mem_sreclaim, &mem_shmem) == 7)
    {
        float mem_used_pct = ((float)mem_used / (float)mem_total) * 100;
        printf("RAM used: %llu kB\tRAM free: %llu kB\tRAM usage: %.2f%%\n",
               mem_used/1024, mem_free/1024, mem_used_pct);
    }

    fclose(meminfo);

    return 0;
}