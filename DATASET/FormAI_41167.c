//FormAI DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Custom memory struct
typedef struct {
    int start_address;
    int end_address;
    int size;
    int is_allocated;
} MemBlock;

MemBlock memory[MAX_SIZE];
int num_blocks = 0;

// Initialize memory with empty blocks
void initialize_memory() {
    int block_size = sizeof(MemBlock);
    int address = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        memory[i].start_address = address;
        memory[i].end_address = address + block_size - 1;
        memory[i].size = block_size;
        memory[i].is_allocated = 0;
        address += block_size;
    }
    num_blocks = MAX_SIZE;
}

// Find the first available block of memory and allocate it
void* allocate_memory(int size) {
    int i, j, count;
    void* ptr = NULL;
    
    for (i = 0; i < num_blocks; i++) {
        if (memory[i].is_allocated == 0 && memory[i].size >= size) {
            count = 0;
            for (j = i; j < num_blocks && count < size; j++) {
                if (memory[j].is_allocated == 0) {
                    count++;
                }
                else {
                    break;
                }
            }
            if (count == size) {
                for (j = i; j < i + size; j++) {
                    memory[j].is_allocated = 1;
                }
                ptr = (void*) memory[i].start_address;
                break;
            }
        }
    }
    return ptr;
}

// Free a block of allocated memory
void free_memory(void* ptr, int size) {
    int i, j;

    for (i = 0; i < num_blocks; i++) {
        if (memory[i].start_address == (int) ptr) {
            for (j = i; j < i + size; j++) {
                memory[j].is_allocated = 0;
            }
            break;
        }
    }
}

int main() {
    initialize_memory();

    // Allocate some memory
    int* p = (int*) allocate_memory(4);
    if (p != NULL) {
        *p = 123;
        printf("Allocated memory at address: %p, value: %d\n", p, *p);
    }

    // Allocate some more memory
    int* q = (int*) allocate_memory(8);
    if (q != NULL) {
        *q = 456;
        printf("Allocated memory at address: %p, value: %d\n", q, *q);
    }

    // Free the memory
    free_memory(p, 4);
    free_memory(q, 8);

    return 0;
}