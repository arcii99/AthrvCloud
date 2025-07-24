//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int cpu_percent;
    long double a[4], b[4], loadavg;
    FILE *fp;

    while (1) {
        
        fp = fopen("/proc/stat", "r");
        fscanf(fp, "%*s %Lf %Lf %Lf %Lf", &a[0], &a[1], &a[2], &a[3]);
        fclose(fp);
        sleep(1);
        
        fp = fopen("/proc/stat","r");
        fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&b[0],&b[1],&b[2],&b[3]);
        fclose(fp);

        loadavg = ((b[0] + b[1] + b[2]) - (a[0] + a[1] + a[2])) / (b[0] + b[1] + b[2] + b[3] + b[0] + b[1] + b[2] + b[3]) * 100;
        
        cpu_percent = (int)loadavg;
        
        printf("\033[1m\033[32m CURRENT CPU USAGE: %d %% \033[0m\n", cpu_percent);
    }

    return 0;

}