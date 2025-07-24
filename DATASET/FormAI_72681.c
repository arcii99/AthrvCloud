//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(void) {

    char buffer[BUFFER_SIZE];
    double cpu_usage[4];
    double usage_percent;

    while (1) {

        FILE* fp = fopen("/proc/stat","r");

        if (fp == NULL) {
            printf("Error: unable to open /proc/stat\n");
            exit(1);
        }

        fgets(buffer, BUFFER_SIZE, fp);
        sscanf(buffer, "cpu %lf %lf %lf %lf", &cpu_usage[0], &cpu_usage[1], &cpu_usage[2], &cpu_usage[3]);

        double prev_idle = cpu_usage[3] + cpu_usage[4];
        double prev_total = prev_idle + cpu_usage[0] + cpu_usage[1] + cpu_usage[2];

        sleep(1);

        rewind(fp);
        fgets(buffer, BUFFER_SIZE, fp);
        sscanf(buffer, "cpu %lf %lf %lf %lf", &cpu_usage[0], &cpu_usage[1], &cpu_usage[2], &cpu_usage[3]);

        double idle = cpu_usage[3] + cpu_usage[4];
        double total = idle + cpu_usage[0] + cpu_usage[1] + cpu_usage[2];

        usage_percent = ((1 - (idle - prev_idle) / (total - prev_total)) * 100);     
        printf("CPU usage: %.2f %%\n", usage_percent);       
        fclose(fp);
    }

    return 0;
}