//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

// Function to get the current RAM usage
double get_ram_usage() {
    struct sysinfo mem_info;

    if (sysinfo(&mem_info) != 0) {
        fprintf(stderr, "Error getting system info\n");
        exit(EXIT_FAILURE);
    }

    long long total_mem = mem_info.totalram;
    total_mem *= mem_info.mem_unit;

    long long free_mem = mem_info.freeram;
    free_mem *= mem_info.mem_unit;

    long long used_mem = total_mem - free_mem;

    return (double) used_mem / total_mem;
}

int main() {
    printf("RAM Usage Monitor\n\n");

    while (1) {
        double ram_usage = get_ram_usage();
        printf("Current RAM Usage: %.2f%%\n", ram_usage * 100);
        sleep(10); // Wait for 10 seconds before checking again
    }

    return 0;
}