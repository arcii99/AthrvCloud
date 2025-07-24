//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main() {
    struct sysinfo info;
    long long total, free, used;

    while(1) {
        // Get system information
        if(sysinfo(&info) != 0) {
            printf("Error: Could not get system information.\n");
            exit(1);
        }

        // Calculate memory usage
        total = info.totalram * info.mem_unit / 1024;
        free = info.freeram * info.mem_unit / 1024;
        used = total - free;

        // Print memory usage statistics
        printf("Total Memory: %lld KB\n", total);
        printf("Used Memory: %lld KB\n", used);
        printf("Free Memory: %lld KB\n", free);
        printf("RAM Usage: %.2f%%\n", ((double)used / (double)total) * 100);

        // Wait for 1 second before refreshing
        sleep(1);
    }

    return 0;
}