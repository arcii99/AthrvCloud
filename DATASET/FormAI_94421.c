//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

void printUsage(struct rusage usage) {
    printf("\n\n\n-----------------------RAM Usage Monitor-----------------------\n");
    printf("User CPU Time: %ld.%06ld seconds\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    printf("System CPU Time: %ld.%06ld seconds\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
    printf("Resident Set Size (RSS): %ld KB\n", usage.ru_maxrss);
    printf("Integral Shared Memory Size: %ld KB\n", usage.ru_ixrss);
    printf("Integral Unshared Data Size: %ld KB\n", usage.ru_idrss);
    printf("Integral Unshared Stack Size: %ld KB\n", usage.ru_isrss);
    printf("Page Reclaims (soft page faults): %ld\n", usage.ru_minflt);
    printf("Page Faults (hard page faults): %ld\n", usage.ru_majflt);
    printf("Swaps: %ld\n", usage.ru_nswap);
    printf("Block Input Operations: %ld\n", usage.ru_inblock);
    printf("Block Output Operations: %ld\n", usage.ru_oublock);
    printf("IPC Messages Sent: %ld\n", usage.ru_msgsnd);
    printf("IPC Messages Received: %ld\n", usage.ru_msgrcv);
    printf("Signals Received: %ld\n", usage.ru_nsignals);
}

int main() {
    int count = 0;
    while (1) {
        struct rusage usage;
        if (getrusage(RUSAGE_SELF, &usage) == -1) {
            printf("Failed to retrieve resource usage.\n");
            exit(EXIT_FAILURE);
        }
        printUsage(usage);
        count++;
        if (count >= 10) {
            break;
        }
        sleep(1);
    }
    printf("Thank you for using the RAM usage monitor program!\n");
    return 0;
}