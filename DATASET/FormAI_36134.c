//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    long long total_mem, free_mem, used_mem;
    char buffer[1000];

    FILE *fp = fopen("/proc/meminfo", "r");
    
    if (fp == NULL) {
        printf("Failed to open /proc/meminfo.\n");
        return 1;
    }
    
    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "MemTotal: %lld kB", &total_mem);
    
    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "MemFree: %lld kB", &free_mem);

    used_mem = total_mem - free_mem;
    
    float percentage_used = (float) used_mem / total_mem * 100;
    
    printf("Total memory: %lld kB\n", total_mem);
    printf("Used memory: %lld kB (%.2f%%)\n", used_mem, percentage_used);
    
    fclose(fp);
    
    return 0;
}