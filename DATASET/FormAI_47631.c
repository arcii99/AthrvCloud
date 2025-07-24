//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFF 512

void print_ram_usage() {
    char buffer[MAX_BUFF];
    FILE* fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        printf("Failed to open /proc/meminfo file.");
        exit(1);
    }
    int mem_total, mem_free, mem_used;
    fgets(buffer, MAX_BUFF, fp);
    sscanf(buffer, "MemTotal: %d kB", &mem_total);
    fgets(buffer, MAX_BUFF, fp);
    sscanf(buffer, "MemFree: %d kB", &mem_free);
    mem_used = mem_total - mem_free;

    printf("RAM usage: %d kB/%d kB\n", mem_used, mem_total);
}

int main() {
    while(1) {
        print_ram_usage();
        sleep(1);
    }
    return 0;
}