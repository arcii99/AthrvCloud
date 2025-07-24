//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
    struct rusage usage;
    struct timeval start, end;
    float cpu_usage;

    // Get start time
    gettimeofday(&start, NULL);

    // Main program logic goes here
    int sum = 0;
    for(int i=0; i<1000000; i++)
    {
        sum += i;
    }

    // Get end time and resource usage
    gettimeofday(&end, NULL);
    getrusage(RUSAGE_SELF, &usage);

    // Calculate CPU usage in percentage
    cpu_usage = ((((usage.ru_utime.tv_sec+usage.ru_stime.tv_sec)*1000000)+
                   (usage.ru_utime.tv_usec+usage.ru_stime.tv_usec))-
                   ((start.tv_sec*1000000)+start.tv_usec))/
                   ((end.tv_sec*1000000)+end.tv_usec) * 100;

    printf("CPU usage: %.2f%%\n", cpu_usage);

    return 0;
}