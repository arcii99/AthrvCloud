//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdlib.h>
#include <stdio.h>

// Defining our statistics structure
struct MemoryStats {
    int totalAllocations;
    int totalDeallocations;
    int totalBytesAllocated;
    int totalBytesDeallocated;
};

// Our memory management functions
void* custom_malloc(size_t size, struct MemoryStats* stats) {
    stats->totalAllocations += 1;
    stats->totalBytesAllocated += size;
    return malloc(size);
}

void custom_free(void* ptr, struct MemoryStats* stats) {
    stats->totalDeallocations += 1;
    stats->totalBytesDeallocated += sizeof(*ptr);
    free(ptr);
}

int main() {
    // Creating our MemoryStats structure
    struct MemoryStats stats = {0, 0, 0, 0};

    // Allocating memory and updating stats
    int* intPtr = (int*)custom_malloc(sizeof(int)*10, &stats);

    // Freeing memory and updating stats
    custom_free(intPtr, &stats);

    // Outputting our stats
    printf("Total Allocations: %d\n", stats.totalAllocations);
    printf("Total Deallocations: %d\n", stats.totalDeallocations);
    printf("Total Bytes Allocated: %d\n", stats.totalBytesAllocated);
    printf("Total Bytes Deallocated: %d\n", stats.totalBytesDeallocated);

    return 0;
}