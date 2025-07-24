//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MB 1048576  // 1 MB in bytes
#define MAX_RAM_USAGE 200  // Maximum RAM usage in MB

int main() {
    int i = 0;
    char *buffer = NULL;
    size_t size = MB;
    int check = 1;
    int used_ram;

    printf("Welcome to the C RAM Usage Monitor!\n");
    printf("This program monitors the amount of RAM used by your C code.\n");

    while (check == 1) {
        buffer = malloc(size);  // Allocate 1 MB of memory
        if (buffer == NULL) {
            printf("Memory allocation failed.\n");
            check = 0;
            break;
        }
        memset(buffer, '0', size);  // Fill memory with '0's

        used_ram = i * MB;  // Calculate RAM usage in MB
        if (used_ram > MAX_RAM_USAGE) {
            printf("Maximum RAM usage of %d MB exceeded. Stopping program.\n", MAX_RAM_USAGE);
            check = 0;
            break;
        }

        printf("Current RAM usage: %d MB.\n", used_ram);
        i++;

        sleep(1);  // Wait for 1 second before re-allocating memory
    }

    printf("Thanks for using our program!\n");

    return 0;
}