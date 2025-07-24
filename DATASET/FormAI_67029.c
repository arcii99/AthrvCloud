//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CPU_USAGE 100

int main()
{
    int previous_total = 0, previous_idle = 0;
    char cpu_info[256];
    float cpu_usage;

    while(1)
    {
        FILE *fp = fopen("/proc/stat", "r");
        if(fp == NULL)
        {
            printf("Error opening /proc/stat file\n");
            exit(1);
        }

        fgets(cpu_info, 256, fp);
        fclose(fp);

        char *token = strtok(cpu_info, " ");
        int total = 0, idle = 0, count = 0;

        while(token != NULL)
        {
            if(count == 0)
            {
                count++;
                token = strtok(NULL, " ");
                continue;
            }

            total += atoi(token);
            if(count == 4)
            {
                idle = atoi(token);
            }

            count++;
            token = strtok(NULL, " ");
        }

        int diff_total = total - previous_total;
        int diff_idle = idle - previous_idle;
        previous_total = total;
        previous_idle = idle;

        cpu_usage = ((float)(diff_total - diff_idle) / diff_total) * 100.0;

        printf("CPU Usage: %f%%\n", cpu_usage);

        if(cpu_usage > MAX_CPU_USAGE)
        {
            printf("The CPU usage has spiked beyond recommended levels!\n");
            printf("Time to call in the detective: Sherlock Holmes!\n");
        }

        sleep(1);
    }

    return 0;
}