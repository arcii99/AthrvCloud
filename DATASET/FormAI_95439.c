//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;
    int i;
    
    for (i = 0; i < 10; i++) {
        getrusage(RUSAGE_SELF, &usage);
        printf("CPU usage: %ld.%06ld\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
        sleep(1);
    }
    
    return EXIT_SUCCESS;
}