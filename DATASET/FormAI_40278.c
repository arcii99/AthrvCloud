//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main() {
    struct sysinfo mem_info;
    while(1) {
        sleep(1);
        if(sysinfo(&mem_info) != 0) {
            printf("Failed to get System Info.\n");
            exit(-1);
        }
        long long total_mem = (long long) mem_info.totalram * mem_info.mem_unit;
        long long free_mem = (long long) mem_info.freeram * mem_info.mem_unit;
        long long used_mem = total_mem - free_mem;
        float used_mem_percentage = ((float)used_mem / (float)total_mem) * 100.0;
        
        system("clear");
        printf("RAM Usage Monitor\n");
        printf("-----------------\n");
        printf("Total Memory: %lld MB\n", total_mem / (1024 * 1024));
        printf("Used Memory: %lld MB\n", used_mem / (1024 * 1024));
        printf("Free Memory: %lld MB\n", free_mem / (1024 * 1024));
        printf("Used Memory Percentage: %.2f %%\n", used_mem_percentage);
    }
    return 0;
}