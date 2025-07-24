//FormAI DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1024
#define BLOCK_SIZE 16

char memory[MEMORY_SIZE]; // allocated memory
int occupied_blocks[MEMORY_SIZE/BLOCK_SIZE] = {0}; // track blocks that are occupied
int num_blocks = MEMORY_SIZE/BLOCK_SIZE; // number of blocks in the allocated memory

// function to display the contents of the memory
void display_memory() {
    printf("\nMemory Status: \n");
    for(int i=0; i<num_blocks; i++) {
        if(i%16 == 0) printf("\n");
        printf("%d ", memory[i]);
    }
    printf("\n\n");
}

// function to allocate memory blocks
void* allocate(int size) {
    // determine the number of blocks needed to allocate the requested size
    int num_needed_blocks = size/BLOCK_SIZE;
    if(size % BLOCK_SIZE != 0) num_needed_blocks++;

    // loop through the blocks and find the first set of contiguous free blocks
    for(int i=0; i<num_blocks; i++) {
        if(!occupied_blocks[i]) {
            int count = 0;
            for(int j=i; j<i+num_needed_blocks; j++) {
                if(j >= num_blocks || occupied_blocks[j]) {
                    count = 0;
                    break;
                }
                count++;
            }
            if(count == num_needed_blocks) {
                for(int j=i; j<i+num_needed_blocks; j++) {
                    occupied_blocks[j] = 1;
                }
                return &memory[i*BLOCK_SIZE];
            }
        }
    }
    // return NULL if there is not enough contiguous free blocks
    return NULL;
}

// function to free memory blocks
void free_block(void* ptr, int size) {
    // determine the starting block of the given ptr
    int start_block = ((char*) ptr - memory) / BLOCK_SIZE;

    // free the blocks occupied by the given ptr
    int num_free_blocks = size/BLOCK_SIZE;
    if(size % BLOCK_SIZE != 0) num_free_blocks++;
    for(int i=start_block; i<start_block+num_free_blocks; i++) {
        occupied_blocks[i] = 0;
        memory[i] = 0;
    }
}

int main() {
    // display initial memory status
    display_memory();

    // allocate memory and display status
    char* ptr1 = (char*) allocate(128);
    if(ptr1 != NULL) {
        printf("Allocated 128 bytes at address: %p\n", ptr1);
        display_memory();
    } else {
        printf("Allocation failed!\n");
    }

    // allocate memory and display status
    char* ptr2 = (char*) allocate(512);
    if(ptr2 != NULL) {
        printf("Allocated 512 bytes at address: %p\n", ptr2);
        display_memory();
    } else {
        printf("Allocation failed!\n");
    }

    // allocate memory and display status
    char* ptr3 = (char*) allocate(256);
    if(ptr3 != NULL) {
        printf("Allocated 256 bytes at address: %p\n", ptr3);
        display_memory();
    } else {
        printf("Allocation failed!\n");
    }

    // free memory blocks and display status
    free_block(ptr1, 128);
    printf("Freed 128 bytes at address: %p\n", ptr1);
    display_memory();

    // allocate memory and display status
    char* ptr4 = (char*) allocate(256);
    if(ptr4 != NULL) {
        printf("Allocated 256 bytes at address: %p\n", ptr4);
        display_memory();
    } else {
        printf("Allocation failed!\n");
    }

    // free memory blocks and display status
    free_block(ptr2, 512);
    printf("Freed 512 bytes at address: %p\n", ptr2);
    display_memory();

    // allocate memory and display status
    char* ptr5 = (char*) allocate(1024);
    if(ptr5 != NULL) {
        printf("Allocated 1024 bytes at address: %p\n", ptr5);
        display_memory();
    } else {
        printf("Allocation failed!\n");
    }

    // free memory blocks and display status
    free_block(ptr3, 256);
    printf("Freed 256 bytes at address: %p\n", ptr3);
    display_memory();

    // free memory blocks and display status
    free_block(ptr4, 256);
    printf("Freed 256 bytes at address: %p\n", ptr4);
    display_memory();

    // free memory blocks and display status
    free_block(ptr5, 1024);
    printf("Freed 1024 bytes at address: %p\n", ptr5);
    display_memory();

    return 0;
}