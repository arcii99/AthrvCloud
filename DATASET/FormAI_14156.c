//FormAI DATASET v1.0 Category: Memory management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of the memory block

// a struct to keep track of the memory block meta data
typedef struct {
    int size; // the size of the memory block
    int is_free; // a flag to indicate whether the memory block is free or not
} mem_block;

// the memory block that we will be using
char memory[MAX_SIZE];

// a function to initialize the memory block
void init_memory() {
    mem_block* first_block = (mem_block*) memory;
    first_block->size = MAX_SIZE - sizeof(mem_block);
    first_block->is_free = 1; // initially, the whole block is free
}

// a function to allocate memory
void* my_malloc(int size) {
    mem_block* block = (mem_block*) memory;

    // search for a free block that is big enough to fit the requested size
    while (block->size < size || !block->is_free) {
        block = (mem_block*) ((char*) block + sizeof(mem_block) + block->size);
        if ((char*) block >= memory + MAX_SIZE) { // we have reached the end of the memory block without finding a suitable block
            return NULL;
        }
    }

    // if we have found a suitable block, divide it into two blocks (the used block and the free block)
    int remaining_size = block->size - size - sizeof(mem_block);
    if (remaining_size > 0) { // if we have enough space for a free block
        mem_block* new_block = (mem_block*) ((char*) block + sizeof(mem_block) + size);
        new_block->size = remaining_size;
        new_block->is_free = 1;

        block->size = size;
    }
    block->is_free = 0;

    // return a pointer to the start of the used block
    return (char*) block + sizeof(mem_block);
}

// a function to free memory
void my_free(void* ptr) {
    if (!ptr) {
        return; // do nothing if the pointer is null
    }

    // find the block containing the pointer
    mem_block* block = (mem_block*) ((char*) ptr - sizeof(mem_block));
    block->is_free = 1;

    // merge with the previous block if it is free
    if (block != (mem_block*) memory && ((mem_block*) ((char*) block - sizeof(mem_block)))->is_free) {
        mem_block* prev_block = (mem_block*) ((char*) block - sizeof(mem_block));
        prev_block->size += sizeof(mem_block) + block->size;
        block = prev_block;
    }

    // merge with the next block if it is free
    if ((char*) block + sizeof(mem_block) + block->size < memory + MAX_SIZE) {
        mem_block* next_block = (mem_block*) ((char*) block + sizeof(mem_block) + block->size);
        if (next_block->is_free) {
            block->size += sizeof(mem_block) + next_block->size;
        }
    }
}

// a function to print the memory block meta data
void print_memory() {
    mem_block* block = (mem_block*) memory;
    while ((char*) block < memory + MAX_SIZE) {
        printf("block at %p, size: %d, is_free: %d\n", block, block->size, block->is_free);
        block = (mem_block*) ((char*) block + sizeof(mem_block) + block->size);
    }
}

int main() {
    init_memory();

    // allocate some memory
    void* ptr1 = my_malloc(100);
    if (!ptr1) {
        printf("failed to allocate memory\n");
        return 1;
    }
    strcpy((char*) ptr1, "hello");

    void* ptr2 = my_malloc(200);
    if (!ptr2) {
        printf("failed to allocate memory\n");
        return 1;
    }
    strcpy((char*) ptr2, "world");

    // free the memory
    my_free(ptr1);

    // allocate some more memory
    void* ptr3 = my_malloc(50);
    if (!ptr3) {
        printf("failed to allocate memory\n");
        return 1;
    }
    strcpy((char*) ptr3, "test");

    // print the memory block meta data
    print_memory();

    return 0;
}