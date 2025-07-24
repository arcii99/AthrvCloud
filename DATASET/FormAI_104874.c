//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main()
{
    struct sysinfo info;
    unsigned long long total_ram, used_ram, free_ram;

    while(1)
    {
        if(sysinfo(&info)==-1)
        {
            printf("Error in sysinfo \n");
            exit(EXIT_FAILURE);
        }

        total_ram = info.totalram;
        used_ram = total_ram - info.freeram;
        free_ram = info.freeram;

        printf("\n===============================\n");
        printf("Total RAM:\t%llu MB\n", (total_ram/1024)/1024);
        printf("Used RAM:\t%llu MB\n", (used_ram/1024)/1024);
        printf("Free RAM:\t%llu MB\n", (free_ram/1024)/1024);
        printf("===============================\n");

        sleep(1);
    }
    
    return 0;
}