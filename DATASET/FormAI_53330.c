//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    struct sysinfo si;
    long double idle_cpu_time, total_cpu_time, prev_total_cpu_time = 0, prev_idle_cpu_time = 0, cpu_usage;
    static char stat[BUF_SIZE];
    FILE *fp;

    while(1) {
        if (!(fp = fopen("/proc/stat", "r"))) {
            printf("Error: Could not open /proc/stat\n");
            exit(1);
        }
        if (!fgets(stat, BUF_SIZE, fp)) {
            printf("Error: Could not read /proc/stat\n");
            exit(1);
        }

        strtok(stat, " ");
        idle_cpu_time = atof(strtok(NULL, " "));
        total_cpu_time = 0;

        for(int i = 0; i < 7; i++) {
            total_cpu_time += atof(strtok(NULL, " "));
        }
        fclose(fp);
        cpu_usage = (1 - ((idle_cpu_time - prev_idle_cpu_time) / (total_cpu_time - prev_total_cpu_time))) * 100;
        prev_idle_cpu_time = idle_cpu_time;
        prev_total_cpu_time = total_cpu_time;
        printf("CPU usage: %Lf%%\n", cpu_usage);
        sysinfo(&si);
        printf("Total RAM: %lu MB\t Free RAM: %lu MB\n", si.totalram / 1024 / 1024, si.freeram / 1024 / 1024);
        sleep(1);
    }
    return 0;
}