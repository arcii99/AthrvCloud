//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_CPU_USAGE 100.0

int main() {
    time_t start = time(NULL);
    time_t end;
    double total_cpu_time_used;
    double cpu_usage;

    while(1) {
        end = time(NULL);
        total_cpu_time_used = (double)(end - start);
        cpu_usage = (total_cpu_time_used / (double)CLOCKS_PER_SEC) * 100.0;
        
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        
        /* Check if the CPU usage is exceeding the MAX_CPU_USAGE */
        if(cpu_usage > MAX_CPU_USAGE) {
            printf("WARNING: CPU usage is too high!\n");
        }
        
        sleep(1); // Sleep for 1 second
    }
    
    return 0;
}