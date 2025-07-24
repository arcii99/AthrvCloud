//FormAI DATASET v1.0 Category: Memory management ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 100
#define FREE 0 
#define USED 1

// Linked list node to keep track of the allocated memory blocks
struct memory_block {
    int start;
    int end;
    struct memory_block* next;
};

typedef struct memory_block MemoryBlock;

// Global Memory Pool
char mem_pool[MEM_SIZE];

// Head of memory block linked list
MemoryBlock* memory_block_head = NULL;

// Function to print the Memory Pool status
void printMemoryPool() {
    printf("==============================\n");
    printf("MEMORY POOL STATUS:\n");
    for (int i = 0; i < MEM_SIZE; ++i) {
        printf("%c", mem_pool[i]);
        if (i == MEM_SIZE - 1) {
            printf("\n\n");
        } else if ((i + 1) % 10 == 0) {
            printf(" ");
        }
    }
}

// Function to allocate memory block of given size
MemoryBlock* allocateMemory(int size) {
    MemoryBlock* new_block = (MemoryBlock*) malloc(sizeof(MemoryBlock));
    int start = 0;
    int end = 0;
    for (int i = 0; i < MEM_SIZE; ++i) {
        if (mem_pool[i] == FREE) {
            if (start == 0) {
                start = i;
            }
            end = i;
            if ((end - start) == size - 1) {
                new_block->start = start;
                new_block->end = end;
                new_block->next = NULL;
                return new_block;
            }
        } else {
            start = 0;
            end = 0;
        }
    }
    return NULL;
}

// Function to free the allocated memory block and merge adjacent free blocks
void freeMemory(MemoryBlock* block) {
    for (int i = block->start; i <= block->end; ++i) {
        mem_pool[i] = FREE;
    }
    MemoryBlock* prev = NULL;
    MemoryBlock* cur = memory_block_head;
    while (cur != NULL) {
        if (cur == block) {
            if (prev == NULL) {
                memory_block_head = block->next;
            } else {
                prev->next = block->next;
            }
            free(block);
            break;
        }
        if ((cur->end + 1) == block->start) {
            cur->end = block->end;
            free(block);
            break;
        }
        if ((block->end + 1) == cur->start) {
            cur->start = block->start;
            free(block);
            break;
        }
        prev = cur;
        cur = cur->next;
    }
}

int main() {
    for (int i = 0; i < MEM_SIZE; ++i) {
        mem_pool[i] = FREE;
    }
    MemoryBlock* block1 = allocateMemory(10);
    if (block1 == NULL) {
        printf("Memory Allocation Failed!\n");
        exit(0);
    }
    for (int i = block1->start; i <= block1->end; ++i) {
        mem_pool[i] = USED;
    }
    printMemoryPool();
    MemoryBlock* block2 = allocateMemory(5);
    if (block2 == NULL) {
        printf("Memory Allocation Failed!\n");
        exit(0);
    }
    for (int i = block2->start; i <= block2->end; ++i) {
        mem_pool[i] = USED;
    }
    printMemoryPool();
    freeMemory(block1);
    printMemoryPool();
    MemoryBlock* block3 = allocateMemory(3);
    if (block3 == NULL) {
        printf("Memory Allocation Failed!\n");
        exit(0);
    }
    for (int i = block3->start; i <= block3->end; ++i) {
        mem_pool[i] = USED;
    }
    printMemoryPool();
    freeMemory(block2);
    freeMemory(block3);
    printMemoryPool();
    return 0;
}