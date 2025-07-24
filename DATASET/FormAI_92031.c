//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
    char buffer[BUFFER_SIZE];
    FILE* fp;

    while(1)
    {
        fp = fopen("/proc/stat","r");

        if(fp == NULL) {
            fprintf(stderr,"Failed to open stat file\n");
            exit(1);
        }

        fgets(buffer,BUFFER_SIZE,fp);

        char cpu[5];
        unsigned long long uptime, idle_time, total_time;
        unsigned long user_time, nice_time, kernel_time, idle_cpu_time;

        sscanf(buffer,"%s %llu %lu %lu %lu %lu %lu %lu", cpu, &uptime, &user_time, &nice_time, &kernel_time, &idle_cpu_time);

        fclose(fp);

        total_time = user_time + nice_time + kernel_time + idle_cpu_time;
        idle_time = idle_cpu_time;

        float idle_percentage = ((float)idle_time/(float)total_time)*100;
        float busy_percentage = 100 - idle_percentage;

        printf("CPU Usage: %.2f%%\n", busy_percentage);

        sleep(1);
    }

    return 0;
}