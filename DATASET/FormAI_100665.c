//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: future-proof
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
    struct rusage ru1, ru2;
    double cpu_usage;

    // Get CPU usage before sleep
    if (getrusage(RUSAGE_SELF, &ru1) == -1) {
        perror("getrusage error");
        return 1;
    }

    // Sleep for 1 second
    sleep(1);

    // Get CPU usage after sleep
    if (getrusage(RUSAGE_SELF, &ru2) == -1) {
        perror("getrusage error");
        return 1;
    }

    // Calculate CPU usage
    cpu_usage = ((double)(ru2.ru_utime.tv_sec - ru1.ru_utime.tv_sec) * 1e6 + (ru2.ru_utime.tv_usec - ru1.ru_utime.tv_usec)) / 1e6;

    // Print CPU usage
    printf("CPU usage: %.2f%%\n", cpu_usage * 100);

    return 0;
}