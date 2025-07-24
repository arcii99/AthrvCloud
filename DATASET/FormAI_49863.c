//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
    struct rusage usage;
    int mB = 1024 * 1024;

    while (1) {
        getrusage(RUSAGE_SELF, &usage);

        printf("Memory usage: %ld MB\n", usage.ru_maxrss / mB);

        sleep(1);
    }

    return 0;
}