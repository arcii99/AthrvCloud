//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

// Function to get the current RAM usage
double get_ram_usage() {
    struct sysinfo info;
    sysinfo(&info);
    return (double)(info.totalram - info.freeram) / (double)info.totalram;
}

int main() {
    double ram_usage;
    while (1) {
        ram_usage = get_ram_usage();
        printf("Current RAM usage: %.2f%%\n", ram_usage * 100.0);
        fflush(stdout);

        // Sleep for 1 second before checking again
        sleep(1);
    }
    return 0;
}