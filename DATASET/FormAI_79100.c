//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;
    int pid = getpid();

    printf("PID: %d\n", pid);

    while (1) {
        if (getrusage(RUSAGE_SELF, &usage) == -1) {
            printf("Error: Could not retrieve resource usage.\n");
            exit(EXIT_FAILURE);
        }

        // Print memory usage statistics
        printf("Memory usage: %ld KB\n", usage.ru_maxrss);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}