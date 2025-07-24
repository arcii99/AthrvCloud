//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/times.h>

int main(){
    struct tms start_time;
    struct tms end_time;
    long ticks_per_second = sysconf(_SC_CLK_TCK);

    long user_time_start, user_time_end;
    long system_time_start, system_time_end;

    times(&start_time);

    while(1){
        //Code to monitor CPU usage
        FILE* stat_file = fopen("/proc/stat", "r");
        char buffer[256];
        fgets(buffer, 256, stat_file);
        fclose(stat_file);

        int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
        sscanf(buffer, "%*s %d %d %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

        printf("CPU Usage: %f%%\n", (float)(user + nice + system) / (float)(user + nice + system + idle) * 100.0);
        sleep(1);

        times(&end_time);

        user_time_start = start_time.tms_utime;
        user_time_end = end_time.tms_utime;
        system_time_start = start_time.tms_stime;
        system_time_end = end_time.tms_stime;

        long user_time_diff = user_time_end - user_time_start;
        long system_time_diff = system_time_end - system_time_start;

        double elapsed_time = (double)(user_time_diff + system_time_diff) / (double)ticks_per_second;
        printf("Time elapsed: %f seconds\n", elapsed_time);

        start_time = end_time;
    }

    return 0;
}