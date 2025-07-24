//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: romantic
#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo si;
    if (sysinfo(&si) != 0)
        return 1;

    long long total_memory = si.totalram * si.mem_unit / 1024 / 1024;
    long long free_memory = si.freeram * si.mem_unit / 1024 / 1024;
    long long used_memory = total_memory - free_memory;

    printf("Total memory: %lld MB\n", total_memory);
    printf("Free memory: %lld MB\n", free_memory);
    printf("Used memory: %lld MB\n", used_memory);

    double used_percent = 1.0 * used_memory / total_memory * 100;
    printf("Used percent: %.2lf%%\n", used_percent);

    return 0;
}