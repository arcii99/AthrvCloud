//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int i, last_idle, last_total;
    int curr_idle, curr_total, diff_idle, diff_total;
    char line[128], cpu[5];

    FILE* fp = fopen("/proc/stat", "r");
    if(fp == NULL) {
        fprintf(stderr, "Error opening /proc/stat\n");
        exit(1);
    }

    fgets(line, sizeof(line), fp);
    sscanf(line, "%s %d %d %d %d %d %d %d", cpu, &last_total, &diff_total, &diff_idle,
                                                &i, &i, &i, &i);
    last_idle = diff_idle;

    fclose(fp);

    while(1) {
        usleep(2000000);

        fp = fopen("/proc/stat", "r");
        if(fp == NULL) {
            fprintf(stderr, "Error opening /proc/stat\n");
            exit(1);
        }

        fgets(line, sizeof(line), fp);
        sscanf(line, "%s %d %d %d %d %d %d %d", cpu, &curr_total, &diff_total, &diff_idle,
                                                &i, &i, &i, &i);
        curr_idle = diff_idle;

        float idle_percent = 100 * (float)(curr_idle - last_idle) / (float)(curr_total - last_total);
        float usage_percent = 100 - idle_percent;
        printf("CPU Usage: %.2f%%\n", usage_percent);

        last_idle = curr_idle;
        last_total = curr_total;

        fclose(fp);
    }
    return 0;
}