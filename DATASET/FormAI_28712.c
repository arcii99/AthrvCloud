//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main()
{
    struct sysinfo info;
    while(1)
    {
        sysinfo(&info);
        long long total_mem = (long long)info.totalram * (long long)info.mem_unit;
        long long free_mem = (long long)info.freeram * (long long)info.mem_unit;
        long long used_mem = total_mem - free_mem;
        float used_mem_percentage = ((float)used_mem / (float)total_mem) * 100;

        printf("\nTotal Memory: %lld bytes\n", total_mem);
        printf("Free Memory: %lld bytes\n", free_mem);
        printf("Used Memory: %lld bytes\n", used_mem);
        printf("Used Memory Percentage: %.2f%%\n", used_mem_percentage);

        sleep(1);
    }
    return 0;
}