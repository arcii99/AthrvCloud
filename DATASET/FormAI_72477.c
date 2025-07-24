//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define KB 1024
#define MB 1048576

int main() {
    int ram_usage = 0;
    int prev_ram_usage = 0;
    int max_ram_usage = 0;
    int min_ram_usage = 999999999;
    int avg_ram_usage = 0;
    int count = 0;

    while (1) {
        FILE *fp;
        char cmd[100];
        strcpy(cmd, "ps -aux | grep YOUR_PROCESS_NAME | grep -v grep | awk '{print $6}'");
        fp = popen(cmd, "r");

        if (fp == NULL) {
            printf("Failed to run command\n");
            exit(1);
        }

        fscanf(fp, "%d", &ram_usage);
        pclose(fp);

        if (ram_usage != prev_ram_usage) {
            printf("\n=========================================\n");
            printf("Current RAM usage: %dKB\n", ram_usage);
            prev_ram_usage = ram_usage;

            // Calculate Max, Min, and Avg
            if (ram_usage > max_ram_usage) {
                max_ram_usage = ram_usage;
            }
            if (ram_usage < min_ram_usage) {
                min_ram_usage = ram_usage;
            }
            avg_ram_usage = ((avg_ram_usage * count) + ram_usage) / (count + 1);
            count++;

            printf("Max RAM usage: %dKB\n", max_ram_usage);
            printf("Min RAM usage: %dKB\n", min_ram_usage);
            printf("Avg RAM usage: %dKB\n", avg_ram_usage);
            printf("=========================================\n");
        }

        // Wait for 5 seconds
        sleep(5);
    }

    return 0;
}