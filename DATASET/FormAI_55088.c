//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    // Get initial total memory 
    struct sysinfo si;   
    sysinfo(&si);
    long long int initial_memory = si.totalram * si.mem_unit;

    // Create infinite loop to monitor memory usage
    while(1) {   
        // Get current memory usage
        sysinfo(&si);
        long long int current_memory = si.totalram * si.mem_unit;
        long long int used_memory = initial_memory - current_memory;
        float percent_used = ((float)used_memory / initial_memory) * 100;

        // Print result to console
        printf("Current RAM usage: %lld bytes, %.2f%% of total\n", used_memory, percent_used);

        // Wait for 1 second before checking again
        sleep(1);
    }

    return 0;
}