//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define CPU_LOAD_LENGTH 11

int main() {
    long double a[CPU_LOAD_LENGTH], b[CPU_LOAD_LENGTH], loadavg;
    register int i;
    for (i = 0; i < CPU_LOAD_LENGTH; i++) {
        FILE *fp;
        char stat[25];
        sprintf(stat, "/proc/stat");
        fp = fopen(stat, "r");
        fscanf(fp, "%*s %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf", &a[i], &a[i + 1], &a[i + 2], &a[i + 3], &a[i + 4], &a[i + 5], &a[i + 6], &a[i + 7], &a[i + 8], &a[i + 9]);
        fclose(fp);
        sleep(1);
    }
    for (i = 0; i < CPU_LOAD_LENGTH; i++) {
        FILE *fp;
        char stat[25];
        sprintf(stat, "/proc/stat");
        fp = fopen(stat, "r");
        fscanf(fp, "%*s %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf", &b[i], &b[i + 1], &b[i + 2], &b[i + 3], &b[i + 4], &b[i + 5], &b[i + 6], &b[i + 7], &b[i + 8], &b[i + 9]);
        fclose(fp);
        sleep(1);
    }
    long double idleTotalDiff[CPU_LOAD_LENGTH], totalDiff[CPU_LOAD_LENGTH];
    for (i = 0; i < CPU_LOAD_LENGTH; i++) {
        idleTotalDiff[i] = b[i] - a[i];
        totalDiff[i] = 0;
        for (int j = 0; j < 10; j++) {
            totalDiff[i] += b[i + j] - a[i + j];
        }
    }
    loadavg = ((totalDiff[0] - idleTotalDiff[0]) * 100)/totalDiff[0];
    printf("CPU usage: %.2Lf%%\n", loadavg);
    return 0;
}