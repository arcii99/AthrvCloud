//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <unistd.h>

#define REFRESH_INTERVAL 1 // interval in seconds
#define TOTAL_MEMORY 8000000000 // total amount of RAM in bytes

int main() {
    long long total_free_memory = 0;
    long long total_used_memory = 0;
    double current_percentage_used = 0; 
    struct sysinfo mem_info;

    while (1) { // infinite loop
        sysinfo(&mem_info);
        total_free_memory = mem_info.freeram * mem_info.mem_unit;
        total_used_memory = TOTAL_MEMORY - total_free_memory;
        current_percentage_used = ((double) total_used_memory / TOTAL_MEMORY) * 100;
        printf("Used memory: %lld bytes (%.2f%%)\n", total_used_memory, current_percentage_used);
        sleep(REFRESH_INTERVAL);
    }

    return 0;
}