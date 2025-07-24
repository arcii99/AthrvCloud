//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CPU 1024

int main() {
    printf("CPU Usage Monitor\n");

    FILE* fp;
    char path[MAX_CPU];
    char line[MAX_CPU];
    float cpuUsage = 0.0;

    while (1) {
        /* Read CPU data from /proc/stat */
        fp = fopen("/proc/stat", "r");
        if(fp == NULL) {
            printf("Error: Failed to open /proc/stat\n");
            exit(EXIT_FAILURE);
        }

        fgets(line, MAX_CPU, fp);

        /* Extract the first CPU usage data */
        sscanf(line, "cpu %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %f", &cpuUsage);

        fclose(fp);

        /* Display the CPU usage percentage in the console */
        printf("CPU Usage: %.2f%%\n", cpuUsage);

        /* Delay for 1s */
        sleep(1);
    }

    return 0;
}