//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: thoughtful
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/resource.h>

int main()
{
    struct rusage usage;
    struct timeval start_time, end_time;
    double cpu_usage;
    int counter = 0;

    printf("CPU Usage Monitor\n");

    while(1)
    {
        printf("Monitoring CPU usage...\n");

        // Get starting time
        gettimeofday(&start_time, NULL);

        // Perform some CPU intensive task
        int i, j, result = 0;
        for(i = 0; i < 1000000; i++)
        {
            for(j = 0; j < 1000000; j++)
            {
                result = i * j;
            }
        }

        // Get ending time
        gettimeofday(&end_time, NULL);

        // Get CPU usage
        getrusage(RUSAGE_SELF, &usage);
        cpu_usage = (double)(usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) +
                (double)(usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / 1000000.0;

        double elapsed_time = (double)(end_time.tv_sec - start_time.tv_sec) +
                (double)(end_time.tv_usec - start_time.tv_usec) / 1000000.0;

        printf("Elapsed time: %f seconds\n", elapsed_time);
        printf("CPU usage: %f %%\n", 100 * cpu_usage / elapsed_time);

        if(counter++ == 10)
        {
            printf("\nExiting the program\n");
            exit(0);
        }
        sleep(1);
    }

    return 0;
}