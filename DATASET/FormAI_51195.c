//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CPUINFO_FILE "/proc/stat"

void print_current_cpu_usage() {
    long double a[4], b[4], loadavg;
    FILE *fp;
    char dump[50];

    fp = fopen(CPUINFO_FILE, "r");
    fscanf(fp, "%*s %Lf %Lf %Lf %Lf", &a[0], &a[1], &a[2], &a[3]);
    fclose(fp);
    sleep(1);

    fp = fopen(CPUINFO_FILE, "r");
    fscanf(fp, "%*s %Lf %Lf %Lf %Lf", &b[0], &b[1], &b[2], &b[3]);
    fclose(fp);

    loadavg = ((b[0] + b[1] + b[2]) - (a[0] + a[1] + a[2])) / ((b[0] + b[1] + b[2] + b[3]) - (a[0] + a[1] + a[2] + a[3])) * 100;

    printf("Current CPU usage: %.2Lf%%\n", loadavg);
}

int main() {
    while (1) {
        print_current_cpu_usage();
    }
    return 0;
}