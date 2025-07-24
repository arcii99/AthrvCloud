//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
    struct rusage usage;
    struct timeval user_start, user_end, sys_start, sys_end;
    double user_time, sys_time;

    printf("Monitoring CPU usage...\n");

    while (1) {
        getrusage(RUSAGE_SELF, &usage);

        user_start = usage.ru_utime;
        sys_start = usage.ru_stime;

        // Add some processing time
        int i, j;
        for (i = 0; i < 1000000; i++) {
            for (j = 0; j < 1000000; j++) {
                // Do nothing
            }
        }

        getrusage(RUSAGE_SELF, &usage);

        user_end = usage.ru_utime;
        sys_end = usage.ru_stime;

        user_time = (user_end.tv_sec - user_start.tv_sec) + (user_end.tv_usec - user_start.tv_usec) / 1000000.0;
        sys_time = (sys_end.tv_sec - sys_start.tv_sec) + (sys_end.tv_usec - sys_start.tv_usec) / 1000000.0;

        printf("User CPU time: %fs\n", user_time);
        printf("System CPU time: %fs\n", sys_time);

        sleep(1); // Wait 1 second before checking again
    }

    return 0;
}