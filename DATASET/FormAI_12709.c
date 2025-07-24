//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;
    long int prev = 0, curr = 0;
    while(1) {
        if(getrusage(RUSAGE_SELF, &usage) == -1) {
            printf("Error: Unable to retrieve resource usage information.\n");
            exit(EXIT_FAILURE);
        }
        // Current program's resident set size (in kilobytes)
        curr = usage.ru_maxrss;
        // Difference in memory usage
        long int delta = curr - prev;
        printf("Current RAM usage: %ld KB\n", curr);
        printf("Delta RAM usage: %ld KB\n", delta);
        prev = curr;
        // Wait for 1 second before checking again
        sleep(1);
    }
    exit(EXIT_SUCCESS);
}