//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main() {
    long double a[4], b[4], loadavg;
    FILE *file;

    while(1) {
        // open the cpu usage stat file
        file = fopen("/proc/stat", "r");
        // scan the first line of the file for cpu usage
        fscanf(file, "%*s %Lf %Lf %Lf %Lf", &a[0], &a[1], &a[2], &a[3]);
        fclose(file);

        // suspend execution for 1 second
        sleep(1);

        // open the cpu usage stat file again
        file = fopen("/proc/stat","r");
        // scan the first line of the file for cpu usage
        fscanf(file, "%*s %Lf %Lf %Lf %Lf", &b[0], &b[1], &b[2], &b[3]);
        fclose(file);
        
        // calculate the cpu usage
        loadavg = ((b[0] + b[1] + b[2]) - (a[0] + a[1] + a[2])) / (b[0] + b[1] + b[2] + b[3] - a[0] - a[1] - a[2] - a[3]) * 100;
        
        // print the cpu usage
        printf("CPU Usage: %.2Lf%%\n", loadavg);
    }
    return 0;
}