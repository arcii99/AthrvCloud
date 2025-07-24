//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    double total_time_1 = 0;
    double idle_time_1 = 0;
    double total_time_2 = 0;
    double idle_time_2 = 0;
    double cpu_usage;

    char cpu_info[10];
    FILE* fp;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fgets(cpu_info, sizeof(cpu_info), fp);

    sscanf(cpu_info, "cpu %lf %*lf %*lf %lf", &total_time_1, &idle_time_1);
    fclose(fp);

    sleep(1);

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fgets(cpu_info, sizeof(cpu_info), fp);

    sscanf(cpu_info, "cpu %lf %*lf %*lf %lf", &total_time_2, &idle_time_2);
    fclose(fp);

    double total_diff = total_time_2 - total_time_1;
    double idle_diff = idle_time_2 - idle_time_1;

    cpu_usage = ((total_diff - idle_diff) / total_diff) * 100;

    printf("CPU Usage is: %.2lf%%\n", cpu_usage);

    return 0;
}