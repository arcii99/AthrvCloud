//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;
    struct timeval start, end;

    while(1) {
        // Get the CPU usage statistics
        if(getrusage(RUSAGE_SELF, &usage) != 0) {
            fprintf(stderr, "Error getting CPU usage statistics.\n");
            exit(1);
        }

        // Get the start time
        gettimeofday(&start, NULL);

        // Do some CPU-intensive work
        int sum = 0;
        for(int i = 0; i < 100000000; i++) {
            sum += i;
        }

        // Get the end time
        gettimeofday(&end, NULL);

        // Calculate the elapsed time
        double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

        // Print the CPU usage statistics and the CPU time used
        printf("CPU usage: user=%ld.%06ld system=%ld.%06ld\n",
               usage.ru_utime.tv_sec, usage.ru_utime.tv_usec,
               usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
        printf("CPU time used: %.6f seconds\n", elapsed);

        // Sleep for a second
        sleep(1);
    }

    return 0;
}