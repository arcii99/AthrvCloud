//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define SECOND_MICRO 1000000

int main(){
    struct rusage usage;
    struct timeval start, end;
    long int startCpu, endCpu;
    double elapsed, cpuUsage;

    getrusage(RUSAGE_SELF, &usage);
    start = usage.ru_stime;
    startCpu = usage.ru_utime.tv_sec * SECOND_MICRO + usage.ru_utime.tv_usec;
    printf("CPU usage monitor program started. Press CTRL + C to stop.\n");

    while(1){
        getrusage(RUSAGE_SELF, &usage);
        end = usage.ru_stime;
        endCpu = usage.ru_utime.tv_sec * SECOND_MICRO + usage.ru_utime.tv_usec;

        elapsed = (double)(end.tv_sec - start.tv_sec) + ((double)(end.tv_usec - start.tv_usec)/SECOND_MICRO);
        cpuUsage = ((double)(endCpu - startCpu)/SECOND_MICRO)/elapsed * 100;
        
        printf("CPU usage: %.2f%%\n", cpuUsage);
        usleep(100000);
    }
    return 0;
}