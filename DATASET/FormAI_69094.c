//FormAI DATASET v1.0 Category: File system simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY_SIZE 1024
#define BLOCK_SIZE 16

unsigned char memory[MAX_MEMORY_SIZE];
int is_allocated[MAX_MEMORY_SIZE / BLOCK_SIZE];

void initialize_memory() {
    for (int i = 0; i < MAX_MEMORY_SIZE; i++) {
        memory[i] = '\0';
    }
    for (int i = 0; i < MAX_MEMORY_SIZE / BLOCK_SIZE; i++) {
        is_allocated[i] = 0;
    }
}

void print_memory() {
    printf("\nMemory: \n");
    for (int i = 0; i < MAX_MEMORY_SIZE; i++) {
        printf("%02x ", memory[i]);
    }
    printf("\n\n");
}

void print_is_allocated() {
    printf("Is Allocated: \n");
    for (int i = 0; i < MAX_MEMORY_SIZE / BLOCK_SIZE; i++) {
        printf("%d ", is_allocated[i]);
    }
    printf("\n\n");
}

int allocate(int size) {
    int blocks_needed = size / BLOCK_SIZE;
    if (size % BLOCK_SIZE != 0) {
        blocks_needed++;
    }
    for (int i = 0; i < MAX_MEMORY_SIZE / BLOCK_SIZE; i++) {
        int j = i;
        while (is_allocated[j] == 0 && j < i + blocks_needed && j < MAX_MEMORY_SIZE / BLOCK_SIZE) {
            j++;
        }
        if (j == i + blocks_needed) {
            for (int k = i; k < j; k++) {
                is_allocated[k] = 1;
            }
            return i * BLOCK_SIZE;
        }
    }
    return -1;
}

void deallocate(int address, int size) {
    int blocks_needed = size / BLOCK_SIZE;
    if (size % BLOCK_SIZE != 0) {
        blocks_needed++;
    }
    int start_index = address / BLOCK_SIZE;
    for (int i = start_index; i < start_index + blocks_needed; i++) {
        is_allocated[i] = 0;
        memory[i * BLOCK_SIZE] = 0;
    }
}

void write_to_memory(int address, char data[]) {
    int len = strlen(data);
    int i;
    for (i = 0; i < len; i++) {
        memory[address + i] = data[i];
    }
    memory[address + i] = '\0';
}

char* read_from_memory(int address) {
    char* data = malloc(sizeof(char) * MAX_MEMORY_SIZE);
    
    int i = 0;
    while (memory[address + i] != '\0') {
        data[i] = memory[address + i];
        i++;
    }
    data[i] = '\0';
    
    return data;
}

int main() {
    initialize_memory();
    
    // Allocate memory
    int address = allocate(32);
    
    // Write to memory
    write_to_memory(address, "Hello, World!");
    
    // Read from memory
    char* data = read_from_memory(address);
    printf("Data at address %d: %s\n", address, data);
    free(data);
    
    // Deallocate memory
    deallocate(address, 32);
    
    // Print memory and is_allocated arrays
    print_memory();
    print_is_allocated();
    
    return 0;
}