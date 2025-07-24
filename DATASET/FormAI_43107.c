//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: relaxed
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>

int main() {
    struct rusage usage;
    struct timeval start, end;
    double cpu_time = 0;
    int i;
    for(i=0; i<100000000; i++) {} // Some arbitrary computation

    getrusage(RUSAGE_SELF, &usage);
    start = usage.ru_utime;
    for(i=0; i<500000000; i++) {} // More arbitrary computation
    getrusage(RUSAGE_SELF, &usage);
    end = usage.ru_utime;

    cpu_time = (double) (end.tv_sec - start.tv_sec) + 
               (double) (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("CPU usage: %f seconds\n", cpu_time);
    return 0;
}