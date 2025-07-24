//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: accurate
#include <stdio.h>

int main() {
    FILE* fp;
    char buf[1024];
    int total_memory, free_memory, used_memory, buffer, cached, shared, sreclaims, sunreclaims;
    fp = fopen("/proc/meminfo", "r");
    if(fp == NULL) {
        printf("Could not open /proc/meminfo\n");
        return 1;
    }
    else {
        fgets(buf, sizeof(buf), fp);
        sscanf(buf, "MemTotal: %d kB", &total_memory);
        fgets(buf, sizeof(buf), fp);
        sscanf(buf, "MemFree: %d kB", &free_memory);
        fgets(buf, sizeof(buf), fp);
        sscanf(buf, "Buffers: %d kB", &buffer);
        fgets(buf, sizeof(buf), fp);
        sscanf(buf, "Cached: %d kB", &cached);
        fgets(buf, sizeof(buf), fp);
        sscanf(buf, "Shmem: %d kB", &shared);
        fgets(buf, sizeof(buf), fp);
        sscanf(buf, "SReclaimable: %d kB", &sreclaims);
        fgets(buf, sizeof(buf), fp);
        sscanf(buf, "SUnreclaim: %d kB", &sunreclaims);
        fclose(fp);
        used_memory = total_memory - free_memory - buffer - cached - shared - sreclaims + sunreclaims;
        printf("Total memory: %d kB\n", total_memory);
        printf("Used memory: %d kB\n", used_memory);
        printf("Free memory: %d kB\n", free_memory);
        printf("Buffer memory: %d kB\n", buffer);
        printf("Cached memory: %d kB\n", cached);
        printf("Shared memory: %d kB\n", shared);
        printf("SReclaimable memory: %d kB\n", sreclaims);
        printf("SUnreclaimable memory: %d kB\n", sunreclaims);
    }
    return 0;
}