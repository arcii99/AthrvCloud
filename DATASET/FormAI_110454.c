//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    double total, idle, usage;
    int interval = 1;
    int count = 0;
    char input[10];

    if(argc > 1) {
        interval = atoi(argv[1]);
        if(interval < 1 || interval > 10) {
            printf("Interval should be between 1 and 10.\n");
            return 1;
        }
    }

    printf("CPU Usage Monitor (Interval: %d seconds)\n", interval);

    while(1) {
        FILE* fp = fopen("/proc/stat", "r");

        if(fp == NULL) {
            printf("Cannot open /proc/stat\n");
            return 1;
        }

        fscanf(fp, "cpu %lf %*f %lf %lf", &total, &idle, &usage);
        fclose(fp);

        printf("%d: CPU Usage: %.2lf%%\n", count, 100 - (idle / total * 100));
        count++;

        sleep(interval);
    }

    return 0;
}