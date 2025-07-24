//FormAI DATASET v1.0 Category: System boot optimizer ; Style: mathematical
#include <stdio.h>

int main() {
    /* Initial boot time */
    double boot_time = 72.85; /* seconds */
  
    /* Define optimization constants */
    const double CPU_FREQ = 3.5; /* GHz */
    const double CACHE_SIZE = 64.0; /* MB */
    const double RAM_SIZE = 8.0; /* GB */
  
    /* Calculate total CPU cycles required for boot */
    double cpu_cycles = boot_time * CPU_FREQ * 1e9;
  
    /* Calculate total data to be transferred from RAM to CPU */
    double data_transferred = RAM_SIZE * 1024.0 * 1024.0 * 1024.0;
  
    /* Calculate the time required to transfer data from RAM to CPU */
    double transfer_time = data_transferred / ((CACHE_SIZE * 1024.0 * 1024.0) / 8.0);
  
    /* Calculate the time required for CPU to process data */
    double cpu_processing_time = cpu_cycles / (CPU_FREQ * 1e9);
  
    /* Calculate the total time required for optimal boot */
    double optimal_boot_time = transfer_time + cpu_processing_time;
  
    /* Calculate percent improvement from initial boot time */
    double percent_improvement = (boot_time - optimal_boot_time) / boot_time * 100.0;
  
    printf("Initial boot time: %.2f seconds\n", boot_time);
    printf("Optimal boot time: %.2f seconds\n", optimal_boot_time);
    printf("Percent improvement: %.2f%%\n", percent_improvement);
  
    return 0;
}