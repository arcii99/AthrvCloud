//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MEMORY_SCALE (1024 * 1024)
#define INTERVAL 1

typedef struct {
    long total_ram;
    long free_ram;
    long cached_ram;
} MemoryUsage;

void get_memory_usage(MemoryUsage* mem) {
    struct sysinfo sys_info;
    if (sysinfo(&sys_info) != 0) {
        fprintf(stderr, "Failed to get system info.\n");
        exit(EXIT_FAILURE);
    }
    mem->total_ram = sys_info.totalram / MEMORY_SCALE;
    mem->free_ram = sys_info.freeram / MEMORY_SCALE;
    mem->cached_ram = sys_info.bufferram / MEMORY_SCALE;
}

int main(int argc, char** argv) {
    MemoryUsage mem;
    while (1) {
        get_memory_usage(&mem);
        printf("\nTotal RAM: %ld MB, Free RAM: %ld MB, Cached RAM: %ld MB\n",
               mem.total_ram, mem.free_ram, mem.cached_ram);
        sleep(INTERVAL);
    }
    return 0;
}