//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp;
    double cpu_usage;
    char unused[100];
    fp = fopen("/proc/stat","r");

    if(fp == NULL){
        printf("Unable to open file");
        exit(1);
    }

    int cpu_idle_time[2], cpu_total_time[2];
    for(int i = 0; i < 2; i++){
        fscanf(fp,"%s %d %d %d %d %d %d %d %d %d", unused, &cpu_total_time[i], unused, unused, unused, unused, unused, unused, &cpu_idle_time[i]);
    }

    fclose(fp);
    cpu_usage = (double) (cpu_total_time[1] - cpu_total_time[0] - (cpu_idle_time[1] - cpu_idle_time[0])) * 100 / (cpu_total_time[1] - cpu_total_time[0]);

    printf("Current CPU Usage: %.2lf%%\n", cpu_usage);

    return 0;

}