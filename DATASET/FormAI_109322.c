//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    long double a[4], b[4], loadavg;
    FILE *fp;

    while (1) { // continuously monitor the CPU usage
        fp = fopen("/proc/stat","r");
        fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&a[0],&a[1],&a[2],&a[3]);
        fclose(fp);
        sleep(1); // wait for one second before checking again
        fp = fopen("/proc/stat","r");
        fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&b[0],&b[1],&b[2],&b[3]);
        fclose(fp);

        loadavg = ((b[0]+b[1]+b[2]) - (a[0]+a[1]+a[2])) / ((b[0]+b[1]+b[2]+b[3]) - (a[0]+a[1]+a[2]+a[3])) * 100;

        printf("Current CPU usage is: %.2Lf %%\n", loadavg);

        if (loadavg > 80) { // send an alert if CPU usage is too high
            printf("WARNING: CPU usage is above 80%%\n");
            // add code here to notify the user or take action
            // such as closing unneeded programs or reducing CPU-intensive tasks
        }
    }

    return 0;
}