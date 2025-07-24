//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

// Function to get memory usage percentage
double get_mem_usage_percentage() {
    struct sysinfo info;
    sysinfo(&info);
    long long total_mem = info.totalram * info.mem_unit;
    long long free_mem = info.freeram * info.mem_unit;
    long long used_mem = total_mem - free_mem;
    double mem_usage_percentage = (double)used_mem / (double)total_mem * 100.0;
    return mem_usage_percentage;
}

int main() {
    while(1) {
        double mem_usage_percentage = get_mem_usage_percentage();
        printf("Memory Usage: %.2lf%%\n", mem_usage_percentage);
        sleep(1);
        system("clear"); // To clear screen after each iteration
    }
    return 0;
}