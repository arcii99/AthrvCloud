//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: automated
#include <stdio.h>
#include <sys/times.h>
#include <unistd.h>

int main()
{
    struct tms tm_start, tm_now;
    clock_t clock_start, clock_now;
    double cpu_percent;

    clock_start = times(&tm_start);

    while (1)
    {
        clock_now = times(&tm_now);
        cpu_percent = (double)(tm_now.tms_utime + tm_now.tms_stime
                                - tm_start.tms_utime - tm_start.tms_stime)
                       / (double)(clock_now - clock_start)
                       / (double)sysconf(_SC_CLK_TCK)
                       * 100.0;

        printf("CPU usage: %.2f%%\n", cpu_percent);

        sleep(1);
    }

    return 0;
}