//FormAI DATASET v1.0 Category: Benchmarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

double get_cpu_time()
{
#ifdef _WIN32
    return (double)clock() / CLOCKS_PER_SEC;
#else
    struct timespec ts;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec / 1000000000.0;
#endif
}

int main()
{
    double cpu_time1, cpu_time2;
    int i, j, temp = 0, a[ARRAY_SIZE];

    for(i = 0; i < ARRAY_SIZE; i++)
    {
        a[i] = rand()%ARRAY_SIZE;
    }

    cpu_time1 = get_cpu_time();

    for(i = 0; i < ARRAY_SIZE - 1; i++)
    {
        for(j = 0; j < ARRAY_SIZE - i - 1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    cpu_time2 = get_cpu_time();

    printf("Total CPU time: %.5f seconds\n", cpu_time2 - cpu_time1);

    return 0;
}