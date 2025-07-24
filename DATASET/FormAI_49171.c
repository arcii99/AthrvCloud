//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to recursively calculate the C RAM usage
int calc_ram_usage(int n) {
    // Allocate n bytes of memory
    char *ptr = malloc(n);

    // Check if memory allocation was successful
    if (ptr == NULL) {
        return -1;
    }

    // Calculate the RAM usage recursively
    int ram_usage = n;
    if (n < 1024) { // Bytes
        printf("RAM usage: %d bytes\n", ram_usage);
    } else if (n < 1024*1024) { // Kilobytes
        ram_usage /= 1024;
        printf("RAM usage: %d KB\n", ram_usage);
    } else { // Megabytes
        ram_usage /= (1024*1024);
        printf("RAM usage: %d MB\n", ram_usage);
    }

    // Free the allocated memory
    free(ptr);

    // Recursively call the function with double the size of memory
    return calc_ram_usage(n * 2);
}

int main() {
    printf("Initializing memory allocation...\n");
    calc_ram_usage(1);

    return 0;
}