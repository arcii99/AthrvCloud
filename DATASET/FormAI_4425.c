//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: systematic
#include <stdio.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main() {

    struct sysinfo cpu_usage;

    while (1) {

        if (sysinfo(&cpu_usage) != 0) {
            printf("Error getting CPU usage.\n");
        }

        long total_cpu_time =
            cpu_usage.totalram - cpu_usage.freeram;
        long process_cpu_time =
            sysconf(_SC_CLK_TCK) * cpu_usage.loads[0] / 100;

        printf("Total CPU time: %ld\n", total_cpu_time);
        printf("Process CPU time: %ld\n", process_cpu_time);
    }

    return 0;
}