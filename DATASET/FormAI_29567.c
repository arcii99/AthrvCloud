//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

#define BUFFER_SIZE 1024
#define SLEEP_TIME_IN_SECS 1

int main(void) {

    double cpu_usage;
    char buffer[BUFFER_SIZE];
    struct timeval current_time;
    struct rusage resource_usage;

    printf("Monitoring CPU usage...\n");

    while (1) {
        getrusage(RUSAGE_SELF, &resource_usage);
        cpu_usage = ((double) resource_usage.ru_utime.tv_sec + (double) resource_usage.ru_utime.tv_usec / 1000000.0
                     + (double) resource_usage.ru_stime.tv_sec + (double) resource_usage.ru_stime.tv_usec / 1000000.0);

        gettimeofday(&current_time, NULL);

        snprintf(buffer, BUFFER_SIZE, "CPU usage is %.2f%% at %ld.%06ld seconds.", cpu_usage * 100,
                 (long int) current_time.tv_sec, (long int) current_time.tv_usec);

        printf("%s\n", buffer);
        sleep(SLEEP_TIME_IN_SECS);
    }

    return 0;
}