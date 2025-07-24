//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Alan Touring
#include <stdio.h>

int main() {
    long long int *mem_ptr;
    int mem_size = 1000000000; // 1 GB
    int i;

    // Allocate memory
    mem_ptr = (long long int *) malloc(mem_size * sizeof(long long int));

    // Check if memory was allocated successfully
    if (mem_ptr == NULL) {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }

    // Fill up memory with data to simulate usage
    for (i = 0; i < mem_size; i++) {
        *(mem_ptr + i) = 1;
    }

    // Monitor memory usage and print out usage percentage every second
    while (1) {
        int mem_used = 0;
        for (i = 0; i < mem_size; i++) {
            if (*(mem_ptr + i) == 1) {
                mem_used++;
            }
        }
        float mem_percentage = ((float) mem_used / (float) mem_size) * 100.0;
        printf("RAM Usage: %.2f%%\n", mem_percentage);
        sleep(1);
    }

    // Free memory before program exits (this line will never be reached in this program)
    free(mem_ptr);

    return 0;
}