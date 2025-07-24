//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main()
{
    while(1)
    {
        struct sysinfo sys_info;
        if(sysinfo(&sys_info) != 0)
        {
            fprintf(stderr,"sysinfo-Error\n");
        }

        long long total_mem = sys_info.totalram;
        total_mem *= sys_info.mem_unit;

        long long free_mem = sys_info.freeram;
        free_mem *= sys_info.mem_unit;

        long long used_mem = total_mem - free_mem;

        double ram_percent = ((double)used_mem/(double)total_mem)*100;

        printf("Total Memory: %lld MB\n",total_mem/(1024*1024));
        printf("Used Memory: %lld MB\n",used_mem/(1024*1024));
        printf("Free Memory: %lld MB\n",free_mem/(1024*1024));
        printf("RAM Usage: %.2f %%\n",ram_percent);

        sleep(5);
        system("clear");
    }

    return 0;
}