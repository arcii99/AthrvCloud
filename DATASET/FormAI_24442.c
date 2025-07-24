//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    struct rusage usage;
    while (1) {
        if (getrusage(RUSAGE_SELF, &usage) != 0) {
            perror("Error: ");
            return 1;
        }
        printf("CPU usage: %ld.%06ld sec user, %ld.%06ld sec system.\n",
               usage.ru_utime.tv_sec, usage.ru_utime.tv_usec,
               usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
        printf("Max resident set size: %ld bytes.\n", usage.ru_maxrss);
        sleep(1);
    }
    return 0;
}