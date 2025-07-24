//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int cpu_usage;
    
    printf("Welcome to CPU usage monitor!\n");
    printf("----------------------------------\n");
    
    while(1)
    {
        FILE* fp = fopen("/proc/stat", "r");
        if(fp == NULL)
        {
            printf("Failed to open /proc/stat\n");
            exit(EXIT_FAILURE);
        }
        
        int user, nice, system, idle, iowait, irq, softirq, steal;
        fscanf(fp, "cpu %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
        
        fclose(fp);
        
        static int prev_idle = 0, prev_total = 0;
        int current_idle = idle, current_total = user + nice + system + idle + iowait + irq + softirq + steal;
        
        int diff_idle = current_idle - prev_idle;
        int diff_total = current_total - prev_total;
        float cpu_usage_float = 100.0 * (diff_total - diff_idle) / diff_total;
        
        cpu_usage = (int)(cpu_usage_float + 0.5);
        
        printf("CPU Usage: %d%%\n", cpu_usage);
        
        prev_idle = current_idle;
        prev_total = current_total;
        
        sleep(1);
    }
    
    return 0;
}