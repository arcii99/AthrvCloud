//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;

    while(1) {
        sysinfo(&info);

        long long total_ram = (long long) info.totalram * (long long) info.mem_unit;
        long long free_ram = (long long) info.freeram * (long long) info.mem_unit;
        long long used_ram = total_ram - free_ram;

        float cpu_usage;
        FILE* cpu_file = fopen("/proc/stat", "r");
        if(cpu_file == NULL) {
            printf("Error opening cpu stats file.");
            return -1;
        }
        long long cpu_1_idle = 0, cpu_1_total = 0;
        fscanf(cpu_file, "cpu %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",
                &cpu_1_idle, &cpu_1_idle, &cpu_1_idle, &cpu_1_idle, &cpu_1_idle, &cpu_1_idle, &cpu_1_idle, &cpu_1_idle, &cpu_1_idle, &cpu_1_total);
        fclose(cpu_file);
        usleep(1000000);
        cpu_file = fopen("/proc/stat", "r");
        if(cpu_file == NULL) {
            printf("Error opening cpu stats file.");
            return -1;
        }
        long long cpu_2_idle = 0, cpu_2_total = 0;
        fscanf(cpu_file, "cpu %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",
                &cpu_2_idle, &cpu_2_idle, &cpu_2_idle, &cpu_2_idle, &cpu_2_idle, &cpu_2_idle, &cpu_2_idle, &cpu_2_idle, &cpu_2_idle, &cpu_2_total);
        fclose(cpu_file);

        long long total_cpu = cpu_2_total - cpu_1_total;
        long long idle_cpu = cpu_2_idle - cpu_1_idle;
        cpu_usage = 100 * (total_cpu - idle_cpu) / (float)total_cpu;

        printf("CPU Usage: %.2f%%\tMemory Usage: %.2f%%\n", cpu_usage, 100.0 * used_ram / total_ram);
    }

    return 0;
}