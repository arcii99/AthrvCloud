//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int main() {

    srand(time(NULL));
    int max_usage = 85; // Maximum RAM usage percentage
    int min_usage = 30; // Minimum RAM usage percentage

    while(1) {
        int current_usage = rand() % (max_usage - min_usage + 1) + min_usage;

        // Calculate the number of bytes based on current RAM usage percentage
        int total_ram = 1024 * 1024 * 16; // Total RAM in bytes
        int current_ram = (current_usage * total_ram) / 100;

        // Allocate a block of memory based on current RAM usage
        char* memory_block = (char*) malloc(current_ram);

        // Fill the memory block with random numbers
        for(int i = 0; i < current_ram; i++) {
            memory_block[i] = rand() % 256;
        }

        printf("Current RAM usage: %d%%\n", current_usage);

        // Sleep for 5 seconds before freeing the memory block
        sleep(5);

        // Free the memory block
        free(memory_block);
    }

    return 0;
}