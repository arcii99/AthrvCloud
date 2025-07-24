//FormAI DATASET v1.0 Category: Memory management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MEM_SIZE 1024 // The memory size is set to 1024 bytes
#define MAX_CHUNKS 10 // Maximum number of chunks that can be allocated from memory

typedef struct {
    void *data;
    size_t size;
} Chunk;

static char mem[MEM_SIZE]; // Our memory buffer
static Chunk chunks[MAX_CHUNKS]; // Array for keeping track of allocated chunks
static int num_chunks = 0; // Variable to keep track of the number of allocated chunks
static pthread_mutex_t mem_lock = PTHREAD_MUTEX_INITIALIZER; // Mutex lock for thread safety

void *allocate(size_t size) {
    pthread_mutex_lock(&mem_lock); // Acquire lock
    if (num_chunks >= MAX_CHUNKS) { // Check if maximum number of chunks have been allocated
        printf("Maximum number of chunks allocated. Unable to allocate more.\n");
        pthread_mutex_unlock(&mem_lock); // Release lock
        return NULL;
    }
    void *bucket = malloc(size); // Allocate memory
    if (bucket == NULL) { // Check if allocation failed
        printf("Memory allocation failed.\n");
        pthread_mutex_unlock(&mem_lock); // Release lock
        return NULL;
    }
    // Add the allocated chunk to the chunks array
    chunks[num_chunks].data = bucket;
    chunks[num_chunks].size = size;
    num_chunks++;
    // Print information about the allocation
    printf("Allocated %zu bytes at %p.\n", size, bucket);
    pthread_mutex_unlock(&mem_lock); // Release lock
    return bucket;
}

void deallocate(void *chunk) {
    pthread_mutex_lock(&mem_lock); // Acquire lock
    int i;
    for (i = 0; i < num_chunks; i++) { // Find the allocated chunk in the chunks array
        if (chunks[i].data == chunk) { // If found, deallocate and remove it from the array
            printf("Deallocated %zu bytes at %p.\n", chunks[i].size, chunks[i].data);
            free(chunk);
            chunks[i] = chunks[num_chunks-1];
            num_chunks--;
            break;
        }
    }
    if (i == num_chunks) { // If the chunk was not found in the array, it was not allocated by our memory manager
        printf("Deallocation failed. Chunk not found.\n");
    }
    pthread_mutex_unlock(&mem_lock); // Release lock
}

int main() {
    // Allocate some memory chunks for testing
    void *chunk1 = allocate(128);
    void *chunk2 = allocate(256);
    void *chunk3 = allocate(64);
    void *chunk4 = allocate(512);
    // Test deallocation
    deallocate(chunk2);
    deallocate(chunk3);
    printf("\nRemaining chunks:\n");
    // Print information about remaining chunks
    int i;
    for (i = 0; i < num_chunks; i++) {
        printf("Chunk %d: %zu bytes at %p.\n", i+1, chunks[i].size, chunks[i].data);
    }
    return 0;
}