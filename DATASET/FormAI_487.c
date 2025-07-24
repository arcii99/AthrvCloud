//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main()
{
    struct sysinfo info;
    long long total_mem, free_mem, used_mem, usage;
    int i;

    while(1)
    {
        if(sysinfo(&info) != 0)
            printf("Error fetching system information.");

        total_mem = (long long) info.totalram * info.mem_unit;
        free_mem = (long long) info.freeram * info.mem_unit;
        used_mem = total_mem - free_mem;

        usage = ((double)used_mem / (double)total_mem) * 100;

        printf("\n------------------------------\n");
        printf("\nTotal memory: \t%lld KB", total_mem / 1024);
        printf("\nFree memory: \t%lld KB", free_mem / 1024);
        printf("\nUsed memory: \t%lld KB", used_mem / 1024);
        printf("\nMemory usage: \t%lld%%", usage);

        sleep(1);
    }

    return 0;
}