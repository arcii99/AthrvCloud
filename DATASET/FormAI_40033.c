//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define DELAY 1

int main() {
    struct sysinfo si;
    bool isFirstLoop = true;
    long double cpuUsage;

    while (true) {
        if (isFirstLoop) {
            isFirstLoop = false;
        } else {
            // Clear console before printing new CPU usage value
            printf("\033[H\033[J");
        }

        if (sysinfo(&si) < 0) {
            perror("sysinfo");
            exit(EXIT_FAILURE);
        }

        cpuUsage = 100 - ((double) si.freeram / si.totalram) * 100;

        printf("CPU USAGE MONITOR\n");
        printf("-------------------------\n\n");
        printf("CPU Usage: %Lf%%\n", cpuUsage);

        sleep(DELAY);
    }

    return 0;
}