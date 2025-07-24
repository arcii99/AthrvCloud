//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

#define ERROR -1

int main()
{
    double cpu_usage = 0.0;
    struct rusage usage;
    struct timeval start, end;

    while(1)
    {
        getrusage(RUSAGE_SELF, &usage);
        start = usage.ru_utime;

        /***********************************/
        /*  Your program logic goes here   */
        /*  This is where you do your work */
        /***********************************/

        getrusage(RUSAGE_SELF, &usage);
        end = usage.ru_utime;

        cpu_usage = ((end.tv_sec - start.tv_sec) * 1000000L + end.tv_usec - start.tv_usec) / 1000000.0;
        printf("\nCPU Usage: %f", cpu_usage);

        if (cpu_usage >= 30.0) //Threshold limit exceeded
        {
            printf("\nCPU usage threshold exceeded! Exiting program...");
            break;
        }
    }

    return 0;
}