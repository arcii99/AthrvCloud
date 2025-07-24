//FormAI DATASET v1.0 Category: System administration ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo si;

    if (sysinfo(&si) != 0) {
        printf("Error getting system info.\n");
        exit(1);
    }

    printf("System uptime: %ld seconds\n", si.uptime);

    return 0;
}