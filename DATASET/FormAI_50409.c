//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
/* 
A Statistical Example Program for C Memory Management
By: [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000 // Size of memory block

int main() {
    char *memblock; // Pointer to memory block
    int i, count = 0;

    memblock = (char *) malloc(sizeof(char) * SIZE); // Allocate memory

    if (memblock == NULL) {
        printf("\nFailed to allocate memory!\n");
        exit(1);
    }
    printf("\nMemory block of size %d allocated successfully!\n", SIZE);

    for (i = 0; i < SIZE; i++) {
        memblock[i] = 'a'; // Fill memory block with 'a'
    }

    printf("\nMemory block filled with %c successfully!\n", memblock[0]);

    for (i = 0; i < SIZE; i += 4) {
        if (memblock[i] == 'a') {
            count++; // Count number of 'a's
        }
    }

    printf("\nNumber of %c's in memory block: %d\n", memblock[0], count);

    free(memblock); // Free memory

    printf("\nMemory block freed successfully!\n");

    return 0;
}