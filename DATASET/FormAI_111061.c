//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    long double a[3], b[3], loadavg;
    FILE *fp;
    char dump[50];

    while (1)
    {
        fp = fopen("/proc/stat", "r");
        fscanf(fp, "%*s %Lf %Lf %Lf %Lf %Lf %Lf %Lf", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]);
        fclose(fp);
        sleep(1);

        fp = fopen("/proc/stat", "r");
        fscanf(fp, "%*s %Lf %Lf %Lf %Lf %Lf %Lf %Lf", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6]);
        fclose(fp);

        loadavg = ((b[0] + b[1] + b[2]) - (a[0] + a[1] + a[2])) / ((b[0] + b[1] + b[2] + b[3] + b[4] + b[5] + b[6]) - (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) * 100;

        system("clear");

        printf("-------------------------------------------------------------\n");
        printf("|                      CPU Usage Monitor                     |\n");
        printf("-------------------------------------------------------------\n\n");
        printf("Current CPU Usage: %.2Lf%%\n\n", loadavg);
        printf("-------------------------------------------------------------\n");

        sleep(2);
    }

    return 0;
}