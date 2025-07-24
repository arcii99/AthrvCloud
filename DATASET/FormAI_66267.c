//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main() {
    struct sysinfo info;
    int minutes = 1; // monitor for 1 minute
    int interval = 5; // update interval in seconds
    int iterations = minutes * 60 / interval;
    unsigned long long total_memory = 0;
    unsigned long long used_memory = 0;
    
    printf("RAM Usage Monitor\n\n");
    
    for (int i = 0; i < iterations; i++) {
        sysinfo(&info);
        unsigned long long memory = info.totalram - info.freeram;
        total_memory += info.totalram;
        used_memory += memory;
        
        char memory_formatted[20];
        sprintf(memory_formatted, "%.2f MB", (double)memory / 1024 / 1024);
        
        int percentage = memory * 100 / info.totalram;
        
        printf("Used RAM: %s (%d%%)\n", memory_formatted, percentage);
        
        sleep(interval);
    }
    
    double average_usage = (double)used_memory / iterations / 1024 / 1024;
    double total_memory_formatted = (double)total_memory / iterations / 1024 / 1024;
    
    printf("\nAverage RAM Usage: %.2f MB (%.2f%%)\n", average_usage, average_usage / total_memory_formatted * 100);
    
    return 0;
}