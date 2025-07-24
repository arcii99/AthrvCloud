//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <unistd.h>

int main(){
    double cpu_usage;
    double idle_time, prev_idle_time = 0;
    double total_time, prev_total_time = 0;
    char cpu_info[50];

    FILE* cpu_info_file = fopen("/proc/stat", "r");
    fgets(cpu_info, 50, cpu_info_file);
    fclose(cpu_info_file);

    sscanf(cpu_info, "cpu %lf %*f %lf %*f %lf %*f %lf %*f %lf", &prev_idle_time, &prev_total_time, &prev_total_time, &prev_total_time, &prev_total_time);

    while(1){
        usleep(500000);

        cpu_info_file = fopen("/proc/stat", "r");
        fgets(cpu_info, 50, cpu_info_file);
        fclose(cpu_info_file);

        sscanf(cpu_info, "cpu %lf %*f %lf %*f %lf %*f %lf %*f %lf", &idle_time, &total_time, &total_time, &total_time, &total_time);

        double total_usage_time = total_time - prev_total_time;
        double idle_usage_time = idle_time - prev_idle_time;
        cpu_usage = 100.0 - (idle_usage_time / total_usage_time) * 100.0;

        printf("CPU Usage: %lf%%\n", cpu_usage);

        prev_idle_time = idle_time;
        prev_total_time = total_time;
    }
    return 0;
}