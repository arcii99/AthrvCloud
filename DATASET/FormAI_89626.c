//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define REFRESH_RATE 1 // Refresh rate in seconds

void print_cpu_usage(){
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    long utime_s = usage.ru_utime.tv_sec;
    long utime_ms = usage.ru_utime.tv_usec / 1000;
    long stime_s = usage.ru_stime.tv_sec;
    long stime_ms = usage.ru_stime.tv_usec / 1000;
    long cpu_time = (utime_s + stime_s);

    printf("CPU Usage: %ld s %ld ms\n", cpu_time, utime_ms + stime_ms);
}

void monitor(int refresh_rate){
    sleep(refresh_rate);
    system("clear"); // Clear the screen
    print_cpu_usage();
    monitor(refresh_rate); // Recurse
}

int main(){
    printf("Press CTRL + C to exit.\n\n");

    monitor(REFRESH_RATE);

    return 0;
}