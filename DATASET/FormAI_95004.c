//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
/* Memory Management Example Program: Statistical Analysis of Memory Usage */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define constants for the size of the memory pool and the number of allocations */
#define POOL_SIZE 100
#define NUM_ALLOCS 20

/* Function to randomly allocate memory */
void allocate_memory(unsigned char *pool)
{
    // Generate random size between 1 and 10 bytes
    int size = rand() % 10 + 1;
    
    // Find first available block of memory
    int i;
    for (i = 0; i < POOL_SIZE - size; i++) {
        if (pool[i] == 0) {
            // Allocate memory block
            int j;
            for (j = 0; j < size; j++) {
                pool[i+j] = 1;
            }
            
            // Print allocation statistics
            printf("Allocated %d bytes starting at index %d\n", size, i);
            return;
        }
    }
    
    // Memory pool is full
    printf("Memory pool is full\n");
}

/* Function to randomly deallocate memory */
void deallocate_memory(unsigned char *pool)
{
    // Find random index of allocated memory block
    int i;
    do {
        i = rand() % POOL_SIZE;
    } while (pool[i] == 0); // Keep looking if index is not currently allocated
    
    // Deallocate memory block
    int size;
    for (size = 1; i+size < POOL_SIZE && pool[i+size] == 1; size++) {
        pool[i+size] = 0;
    }
    
    // Print deallocation statistics
    printf("Deallocated %d bytes starting at index %d\n", size, i);
}

int main()
{
    // Allocate memory pool
    unsigned char *pool = (unsigned char*) malloc(POOL_SIZE * sizeof(unsigned char));
    if (pool == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }
    
    // Seed random number generator
    srand(time(NULL));
    
    // Perform random memory allocations and deallocations
    int i;
    for (i = 0; i < NUM_ALLOCS; i++) {
        int decision = rand() % 2;
        if (decision == 0) {
            allocate_memory(pool);
        } else {
            deallocate_memory(pool);
        }
    }
    
    // Free memory pool
    free(pool);
    
    return 0;
}