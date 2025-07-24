//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define INTERVAL 1
#define MB 1024*1024

int main()
{
    struct sysinfo sys_info;
    double total_cpu_usage = 0;
    int count = 0;
    printf("CPU Usage Monitor\n");
    printf("Press Ctrl+C to exit\n");
    while(1) {
        sysinfo(&sys_info);
        double load_avg_1 = sys_info.loads[0]/(double)(1<<SI_LOAD_SHIFT);
        double load_avg_5 = sys_info.loads[1]/(double)(1<<SI_LOAD_SHIFT);
        double load_avg_15 = sys_info.loads[2]/(double)(1<<SI_LOAD_SHIFT);
        printf("Load Average (1min/5min/15min): %.2f/%.2f/%.2f\n", load_avg_1, load_avg_5, load_avg_15);

        FILE *fp = fopen("/proc/stat", "r");
        fscanf(fp, "cpu %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %lf", &total_cpu_usage);
        fclose(fp);
        printf("CPU Usage: %.2f%%\n", total_cpu_usage/count);
        count++;
        sleep(INTERVAL);
    }
    return 0;
}