//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: minimalist
#include <stdio.h>
#include <unistd.h>

int main() {
    long long pagetotal, pagefree, pagesize, buffered, cached, active, inactive;
    char buf[512];

    FILE *meminfo = fopen("/proc/meminfo", "r");
    if (meminfo == NULL) {
        perror("Error opening /proc/meminfo");
        return -1;
    }

    while(fgets(buf, sizeof(buf), meminfo)) {
        if (sscanf(buf, "MemTotal: %lld kB", &pagetotal) == 1) {
            pagesize = (pagetotal << 10) / (1 << 20); // in MB
        }
        if (sscanf(buf, "MemFree: %lld kB", &pagefree) == 1) {
            printf("RAM usage: %lld MB used / %lld MB total\n",
                (pagetotal - pagefree) * pagesize, pagetotal * pagesize);
            break;
        }
        if (sscanf(buf, "Buffers: %lld kB", &buffered) == 1) {
            continue;
        }
        if (sscanf(buf, "Cached: %lld kB", &cached) == 1) {
            continue;
        }
        if (sscanf(buf, "Active: %lld kB", &active) == 1) {
            continue;
        }
        if (sscanf(buf, "Inactive: %lld kB", &inactive) == 1) {
            continue;
        }
    }

    fclose(meminfo);
    return 0;
}