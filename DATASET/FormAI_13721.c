//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Starting RAM usage monitor...\n");

    char command[50];
    long int total_mem, free_mem, used_mem;

    while(1) {
        // Get total memory
        strcpy(command, "grep MemTotal /proc/meminfo | awk '{print $2}'");
        total_mem = strtol(system(command), NULL, 10);

        // Get free memory
        strcpy(command, "grep MemFree /proc/meminfo | awk '{print $2}'");
        free_mem = strtol(system(command), NULL, 10);

        // Calculate used memory
        used_mem = total_mem - free_mem;

        // Print results
        printf("Total: %ld KB\t", total_mem);
        printf("Free: %ld KB\t", free_mem);
        printf("Used: %ld KB\n", used_mem);

        // Wait for 1 second before checking again
        sleep(1);
    }

    return 0;
}