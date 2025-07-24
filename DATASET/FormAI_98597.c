//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned long long total_mem, free_mem, used_mem;
    char buffer[1024];
    FILE* fp = fopen("/proc/meminfo", "r");
    if(fp == NULL) {
        printf("Error: Unable to open /proc/meminfo\n");
        return 1;
    }
    while(fgets(buffer, sizeof(buffer), fp)) {
        if(sscanf(buffer, "MemTotal: %llu kB", &total_mem) == 1) {
            continue;
        } else if(sscanf(buffer, "MemFree: %llu kB", &free_mem) == 1) {
            continue;
        }
    }
    fclose(fp);
    used_mem = total_mem - free_mem;
    double used_percent = (double)used_mem/total_mem * 100;
    printf("Total Memory: %llu kB\n", total_mem);
    printf("Free Memory: %llu kB\n", free_mem);
    printf("Used Memory: %llu kB\n", used_mem);
    printf("Used Memory Percent: %.2lf%%\n", used_percent);
    return 0;
}