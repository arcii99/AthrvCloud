//FormAI DATASET v1.0 Category: Memory management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MEMORY_SIZE 1000
#define BLOCK_SIZE 20

struct Block {
    int size;
    struct Block* next;
};

char memory[MEMORY_SIZE];    // The available memory space
struct Block* head = NULL;  // Head of the linked list of Blocks in memory

void allocate_memory();
void free_memory();
void print_memory();
void signal_handler(int signal);

int main() {
    srand(time(NULL));

    // Register signal handler for CTRL+C
    signal(SIGINT, signal_handler);

    // Allocate initial memory block
    allocate_memory();

    // Randomly allocate and free memory blocks for demonstration purposes
    while(1) {
        int allocate = rand() % 2;
        if(allocate) {
            int size = BLOCK_SIZE * (rand() % 10 + 1); // Allocate between 20-200 bytes
            if(size <= MEMORY_SIZE) {
                printf("\nAllocating memory of size %d...", size);
                struct Block* ptr = head;
                while(ptr) {
                    if(!ptr->next) {
                        struct Block* new_block = (struct Block*) (memory + ((ptr - (struct Block*) memory) + ptr->size));
                        new_block->size = size;
                        ptr->next = new_block;
                        new_block->next = NULL;

                        printf("\n\tAllocated memory block starting at address %p with size %d.", new_block, new_block->size);
                        break;
                    }
                    ptr = ptr->next;
                }
            }
        } else {
            free_memory();
        }

        print_memory();
        sleep(2); // Wait for 2 seconds before attempting next memory allocation/free
    }

    return 0;
}

void allocate_memory() {
    printf("\nAllocating initial memory block...");
    head = (struct Block*) memory;
    head->size = MEMORY_SIZE - sizeof(struct Block);
    head->next = NULL;

    printf("\n\tAllocated memory block starting at address %p with size %d.", head, head->size);
}

void free_memory() {
    if(head->next == NULL) {
        printf("\nNo memory blocks to free.");
        return;
    }

    struct Block* ptr = head->next;
    while(ptr) {
        if(ptr->next == NULL) {
            printf("\nFreeing memory block starting at address %p with size %d.", ptr, ptr->size);
            head->next = NULL;
            break;
        }
        ptr = ptr->next;
    }
}

void print_memory() {
    printf("\nMemory Contents:\n");

    struct Block* ptr = head;
    while(ptr) {
        printf("%p-[ %d ]-", ptr, ptr->size);
        for(int i = 0; i < ptr->size; i++) {
            printf("%c", memory[((ptr - (struct Block*) memory) + i)]);
        }
        ptr = ptr->next;
    }

    printf("\n\n");
}

void signal_handler(int signal) {
    printf("\nReceived signal %d. Freeing all memory blocks...", signal);

    // Free all memory blocks
    while(head->next) {
        free_memory();
    }

    exit(signal);
}