//FormAI DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

// Function to initialize memory
void initialize_memory(char *buffer, int size) {
    for (int i = 0; i < size; i++) {
        buffer[i] = '\0';
    }
}

// Function to allocate memory
char* allocate_memory(char *buffer, int size) {
    int i = 0;

    // Find first empty slot of required size
    while (buffer[i] != '\0') {
        i += buffer[i] + 1;
    }

    int empty_slot = i;
    int remaining_size = size;

    // Check if memory can be allocated
    while (buffer[i] != '\0') {
        int slot_size = buffer[i];

        if (remaining_size <= slot_size) {
            int next_slot = i + slot_size + 1;
            buffer[empty_slot] = size;
            buffer[next_slot - 1] = slot_size - remaining_size;
            return buffer + empty_slot + 1;
        }

        i += slot_size + 1;
        empty_slot = i;
        remaining_size -= slot_size;
    }

    // If memory can't be allocated return NULL
    return NULL;
}

// Function to free memory
void free_memory(char *buffer, char *ptr) {
    int i = 0;

    // Find the memory block to be freed
    while (buffer + i != ptr) {
        i += buffer[i] + 1;
    }

    // Combine adjacent free memory blocks
    int current_slot = i;
    int next_slot = i + buffer[i] + 1;

    while (next_slot < SIZE && buffer[next_slot] != '\0') {
        buffer[current_slot] += (buffer[next_slot] + 1);
        next_slot += buffer[next_slot] + 1;
    }

    // Free up memory block
    buffer[current_slot] = 0;
}

int main() {
    // Initialize memory buffer
    char memory[SIZE];
    initialize_memory(memory, SIZE);

    // Allocate and free memory
    char *ptr1 = allocate_memory(memory, 512);
    char *ptr2 = allocate_memory(memory, 1024);
    char *ptr3 = allocate_memory(memory, 2048);

    printf("Memory is allocated to ptr1: %p\n", ptr1);
    printf("Memory is allocated to ptr2: %p\n", ptr2);
    printf("Memory is allocated to ptr3: %p\n", ptr3);

    free_memory(memory, ptr1);
    printf("Memory is freed from ptr1\n");

    char *ptr4 = allocate_memory(memory, 512);
    printf("Memory is allocated to ptr4: %p\n", ptr4);

    return 0;
}