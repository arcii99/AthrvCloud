//FormAI DATASET v1.0 Category: Memory management ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void* myMalloc(size_t size);
void myFree(void* ptr);

static char memoryPool[MAX_SIZE];
static size_t currentOffset = 0;

int main() {
    int* numbers = (int*) myMalloc(3 * sizeof(int));
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;

    printf("Numbers: %d %d %d\n", numbers[0], numbers[1], numbers[2]);

    myFree(numbers);

    return 0;
}

void* myMalloc(size_t size) {
    if (currentOffset + size > MAX_SIZE) {
        return NULL;
    }

    void* ptr = &memoryPool[currentOffset];
    currentOffset += size;

    return ptr;
}

void myFree(void* ptr) {
    // It's a no-op since our implementation doesn't actually free the memory.
    // This is just to satisfy the compiler.
    return;
}