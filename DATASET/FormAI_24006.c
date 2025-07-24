//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MAX_PROC_NAME 256

int main(int argc, char **argv) {
    char buf[MAX_PROC_NAME];
    struct sysinfo info;
    long double loadavg[3], percent;

    // Loop forever
    while (1) {
        // Get system information
        if (sysinfo(&info) != 0) {
            fprintf(stderr, "Error getting system info!\n");
            exit(EXIT_FAILURE);
        }

        // Get the load average
        if (getloadavg(loadavg, 3) == -1) {
            fprintf(stderr, "Error getting load average!\n");
            exit(EXIT_FAILURE);
        }

        // Calculate CPU usage as a percentage
        percent = (loadavg[0] * 100.0) / sysconf(_SC_NPROCESSORS_ONLN);

        // Print system information and CPU usage
        sprintf(buf, "CPU %.2Lf%% | Mem: %ld/%ld MB | Uptime: %ld:%02ld:%02ld",
                percent, (info.totalram - info.freeram) / 1024 / 1024, info.totalram / 1024 / 1024,
                info.uptime / 3600, (info.uptime % 3600) / 60, info.uptime % 60);
        printf("%s\r", buf);
        fflush(stdout);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}