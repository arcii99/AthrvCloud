//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    printf("CPU Usage Monitor\n\n");

    struct rusage usage;
    struct timeval start, end;
    long int usertime, systemtime;
    float cpuusage;

    while(1) {
        getrusage(RUSAGE_SELF, &usage); // get CPU usage
        gettimeofday(&start, NULL); // get start time

        // Do some CPU intensive task
        for(int i = 0; i < 10000000; i++) {
            int j = i * i;
        }

        gettimeofday(&end, NULL); // get end time

        usertime = (usage.ru_utime.tv_sec * 1000000 + usage.ru_utime.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
        systemtime = (usage.ru_stime.tv_sec * 1000000 + usage.ru_stime.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
        cpuusage = ((float)(usertime + systemtime) / ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec))) * 100;

        printf("CPU Usage: %.2f%%\n", cpuusage); // print CPU usage
        sleep(1); // wait for 1 second
    }

    return 0;
}