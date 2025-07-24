//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    unsigned long long pre_total_ticks = 0, pre_idle_ticks = 0;
    int cpu_count = sysconf(_SC_NPROCESSORS_CONF);
    while(1)
    {
        FILE* fp = fopen("/proc/stat", "r");
        if(fp == NULL) exit(-1);

        char buf[512];
        fgets(buf, sizeof(buf), fp);
        fclose(fp);
        char name[64];
        unsigned long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
        sscanf(buf, "%s %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", name, &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

        unsigned long long total_ticks = user + nice + system + idle + iowait + irq + softirq + steal;
        unsigned long long idle_ticks = idle;
        unsigned long long total_ticks_diff = total_ticks - pre_total_ticks;
        unsigned long long idle_ticks_diff = idle_ticks - pre_idle_ticks;
        double usage = 100.0 * (total_ticks_diff - idle_ticks_diff) / total_ticks_diff;
        printf("\x1b[2;0f"); //Move cursor to (2, 0)
        printf("CPU Usage: %.2f%%\n", usage/cpu_count);

        pre_total_ticks = total_ticks;
        pre_idle_ticks = idle_ticks;

        usleep(200000);
    }
    return 0;
}