//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;
    int usage_value;
    while (1) {
        if (getrusage(RUSAGE_SELF, &usage) == -1) {
            fprintf(stderr, "Error: Unable to retrieve CPU usage.\n");
            exit(EXIT_FAILURE);
        }
        usage_value = (int) (usage.ru_maxrss / 1024);
        printf("Current RAM usage: %dMB\n", usage_value);
        sleep(1);
    }
    return 0;
}