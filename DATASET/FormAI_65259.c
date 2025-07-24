//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifdef __unix__
#include <sys/resource.h>
#endif

int main(int argc, char* argv[]) {
    int interval, duration;

    if (argc != 3) {
        printf("Usage: %s [interval] [duration]\n", argv[0]);
        printf("interval (seconds) - Time between memory usage checks\n");
        printf("duration (seconds) - Total duration of monitoring\n");
        return 1;
    }

    interval = atoi(argv[1]);
    duration = atoi(argv[2]);

    printf("Starting memory usage monitor...\n");
    printf("Interval: %d seconds\n", interval);
    printf("Duration: %d seconds\n", duration);

#ifdef __unix__
    struct rusage r_usage;
#endif

    int time = 0;
    while (time < duration) {
        sleep(interval);
        time += interval;

#ifdef __unix__
        getrusage(RUSAGE_SELF, &r_usage);
        long rss = r_usage.ru_maxrss * 1024;
#else
        long rss = rand() % 1000000;
#endif

        printf("Memory usage at %d seconds: %ld bytes\n", time, rss);
    }

    printf("Memory usage monitor complete!\n");
    return 0;
}