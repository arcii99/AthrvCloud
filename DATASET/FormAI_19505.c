//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_ALLOCS 25000

int main() {
    srand(time(0));
    void* pointers[MAX_ALLOCS];
    int sizes[MAX_ALLOCS], num_allocs = 0;

    int mem_free = MAX_SIZE;
    int mem_usage = 0;

    printf("Starting memory allocation simulator...\n");

    while (num_allocs < MAX_ALLOCS) {
        int size = rand() % 100 + 1; // random size between 1 and 100
        if (size > mem_free) {
            printf("Memory allocation failed: not enough free memory.\n");
            break;
        }

        void* pointer = malloc(size);
        if (!pointer) {
            printf("Memory allocation failed: could not allocate memory.\n");
            break;
        }

        pointers[num_allocs] = pointer;
        sizes[num_allocs] = size;
        num_allocs++;
        mem_usage += size;
        mem_free -= size;

        printf("Allocated %d bytes of memory, %d bytes free, %d bytes used.\n", size, mem_free, mem_usage);
    }

    printf("Simulator finished: allocated %d blocks of memory, %d bytes free, %d bytes used.\n", num_allocs, mem_free, mem_usage);

    return 0;
}