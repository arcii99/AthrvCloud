//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
    struct rusage usage;
    struct timeval start, end, elapsed;

    int iterations = 0;
    double total_cpu_time = 0;

    while(iterations < 10)
    {
        gettimeofday(&start, NULL);

        getrusage(RUSAGE_SELF, &usage);
        double cpu_time = (double) (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) 
                        + (double) (usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / 1000000;

        gettimeofday(&end, NULL);

        timersub(&end, &start, &elapsed);

        printf("\033[2J\033[1;1H");
        printf("\033[1;34mCPU USAGE MONITOR\033[0m\n");
        printf("Iteration: %d\n", iterations + 1);
        printf("---------------------------\n");
        printf("\033[1;31mCPU Time: %.2fs\033[0m\n", cpu_time);
        printf("\033[1;33mTotal CPU Time: %.2fs\033[0m\n", total_cpu_time + cpu_time);
        printf("\033[1;32mElapsed Time: %.2fs\033[0m\n", (double) elapsed.tv_sec + (double) elapsed.tv_usec / 1000000);
        
        fflush(stdout);

        total_cpu_time += cpu_time;
        iterations++;
        sleep(1);
    }

    return 0;
}