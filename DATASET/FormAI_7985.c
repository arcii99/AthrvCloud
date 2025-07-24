//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#define INTERVAL 1

int main()
{
    struct sysinfo info;
    int Mb = 1024 * 1024;
    while (1)
    {
        sysinfo(&info);
        long long total_memory = (long long)info.totalram * info.mem_unit / Mb;
        long long free_memory = (long long)info.freeram * info.mem_unit / Mb;
        long long used_memory = total_memory - free_memory;
        printf("Total memory: %lld MB\t", total_memory);
        printf("Used memory: %lld MB\t", used_memory);
        printf("Free memory: %lld MB\t", free_memory);
        printf("RAM usage: %.2f%%\n", ((float)(used_memory * 100) / total_memory));
        sleep(INTERVAL);
    }
    return 0;
}