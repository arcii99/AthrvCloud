//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: excited
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/times.h>
#include<time.h>

int main() {
    struct tms start, end;
    long int tics_per_second, cpu_time;
    clock_t real_time;
    unsigned long int prev_idle_time = 0, prev_total_time = 0;

    tics_per_second = sysconf(_SC_CLK_TCK);
    printf("Let's monitor CPU usage!\n");

    while(1) {
        times(&start);
        real_time = clock();

        FILE* fp = fopen("/proc/stat", "r");
        unsigned long int user_time, nice_time, system_time, idle_time, io_time, irq_time, softirq_time;
        fscanf(fp, "cpu %lu %lu %lu %lu %lu %lu %lu", &user_time, &nice_time, &system_time, &idle_time, &io_time, &irq_time, &softirq_time);
        fclose(fp);

        unsigned long int total_time = user_time + nice_time + system_time + idle_time + io_time + irq_time + softirq_time;
        unsigned long int idle_delta = idle_time - prev_idle_time;
        unsigned long int total_delta = total_time - prev_total_time;

        float cpu_usage = ((float)total_delta - (float)idle_delta)/(float)total_delta * 100.0;
        cpu_time = (long int)(cpu_usage * ((float)real_time / (float)tics_per_second));

        printf("CPU usage: %0.2f%%\n", cpu_usage);
        printf("CPU time used: %ld ticks\n", cpu_time);

        prev_idle_time = idle_time;
        prev_total_time = total_time;

        times(&end);
        sleep(1);
    }
    return 0;
}