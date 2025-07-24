//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

float cpu_usage;

void* monitor_cpu(void* args){
    long int cpu_total_prev, cpu_idle_prev;
    long int cpu_total_curr, cpu_idle_curr;
    FILE* fp = fopen("/proc/stat", "r");
    fscanf(fp, "%*s %ld %*s %ld", &cpu_total_prev, &cpu_idle_prev);
    fclose(fp);

    while(1){
        sleep(1);
        fp = fopen("/proc/stat", "r");
        fscanf(fp, "%*s %ld %*s %ld", &cpu_total_curr, &cpu_idle_curr);
        fclose(fp);

        long int cpu_total_diff = cpu_total_curr - cpu_total_prev;
        long int cpu_idle_diff = cpu_idle_curr - cpu_idle_prev;
        cpu_usage = (float)(cpu_total_diff - cpu_idle_diff) * 100.0 / cpu_total_diff;
        cpu_total_prev = cpu_total_curr;
        cpu_idle_prev = cpu_idle_curr;
    }
}

int main(){
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, monitor_cpu, NULL);

    while(1){
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        usleep(500000);
    }

    return 0;
}