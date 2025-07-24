//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/resource.h>

/* Declare monitor function */
void monitor_memory_usage();

int main() {
    /* Call the memory monitor */
    monitor_memory_usage();

    return 0;
}

/* Define monitor function */
void monitor_memory_usage() {
    struct rusage usage;
    while(1) {
        /* Get the current memory usage */
        getrusage(RUSAGE_SELF, &usage);
        double rss = usage.ru_maxrss / 1024.0;

        /* Print out the usage */
        printf("Current RAM usage: %f MB\n", rss);

        /* Sleep for one second */
        sleep(1);
    }
}