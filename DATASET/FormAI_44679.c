//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/times.h>

float get_cpu_usage()
{
    struct tms startTime, endTime;
    clock_t start, end;
    float cpu_usage;

    start = times(&startTime);

    // Some processing
    int a = 1;
    int b = 2;
    int c = a + b;
    sleep(1);

    end = times(&endTime);

    // Calculate CPU usage
    cpu_usage = (float)(endTime.tms_utime + endTime.tms_stime - startTime.tms_utime - startTime.tms_stime) / (float)(end - start) * 100;
    return cpu_usage;
}

int main()
{
    float cpu_usage;
    while(1)
    {
        cpu_usage = get_cpu_usage();
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        if(cpu_usage > 80)
        {
            printf("High CPU usage. Taking action.\n");
            // Take some action here, like killing a process consuming high CPU resources
            break;
        }
        sleep(1);
    }
    return 0;
}