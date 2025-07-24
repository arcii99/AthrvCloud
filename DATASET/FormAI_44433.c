//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MB (1024*1024)

int main()
{
    struct sysinfo info;
    long long total_mem, free_mem;
    int usage_percent;

    while(1)
    {
        //Get system information
        if(sysinfo(&info) == -1)
        {
            perror("sysinfo");
            exit(EXIT_FAILURE);
        }

        //Calculate memory usage
        total_mem = (long long)info.totalram * (long long)info.mem_unit;
        free_mem = (long long)info.freeram * (long long)info.mem_unit;
        usage_percent = (int)(((double)(total_mem - free_mem)) / (double)total_mem * 100.0);

        //Print usage percentage
        printf("Memory Usage: %d%%\n", usage_percent);

        //Sleep for 1 second
        sleep(1);
    }

    return 0;
}