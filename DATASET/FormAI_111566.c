//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main(void) {
    struct sysinfo info;
    int timeout = 5; // seconds

    while (1) {
        if (sysinfo(&info) != 0) {
            fprintf(stderr, "Unable to fetch system information");
            continue;
        }

        double total_cpu_time = (double)info.totalram - (double)info.freeram;
        double used_cpu_percent = (total_cpu_time / (double)info.totalram) * 100.0;

        printf("Current CPU usage: %.2f%%\n", used_cpu_percent);
        sleep(timeout);
    }

    return EXIT_SUCCESS;
}