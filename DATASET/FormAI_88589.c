//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE 1024

int main()
{
    char buffer[SIZE];
    long double prev_idle, prev_total, idle, total, usage;
    FILE* file1 = fopen("/proc/stat", "r");
    if (!file1) {
        printf("Error: couldn't open /proc/stat.\n");
        exit(EXIT_FAILURE);
    }
    fscanf(file1, "%*s %Lf %Lf %Lf %Lf %Lf %Lf %Lf", &prev_idle, &prev_idle, &prev_idle, &prev_idle, &prev_idle, &prev_idle, &prev_total);
    fclose(file1);
    while (1) {
        FILE* file2 = fopen("/proc/stat", "r");
        if (!file2) {
            printf("Error: couldn't open /proc/stat.\n");
            exit(EXIT_FAILURE);
        }
        fscanf(file2, "%*s %Lf %Lf %Lf %Lf %Lf %Lf %Lf", &idle, &idle, &idle, &idle, &idle, &idle, &total);
        fclose(file2);
        usage = 100.0 * (1.0 - (idle - prev_idle) / (total - prev_total));
        printf("CPU usage: %.2Lf%%\n", usage);
        prev_idle = idle;
        prev_total = total;
        sleep(1);
    }
    return 0;
}