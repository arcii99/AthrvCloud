//FormAI DATASET v1.0 Category: Memory management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *memory = malloc(sizeof(int) * 10);
    int i;

    printf("Welcome to the Memory Management Program of the Surrealist League!\n\n");

    printf("You have been allocated 10 integers of memory at address: %p\n", memory);

    for(i = 0; i < 10; i++) {
        memory[i] = rand() % 1000;
        printf("Memory location %p contains the value: %d\n", &memory[i], memory[i]);
    }

    printf("\nNow, let's surprise ourselves by freeing the memory in a surreal way:\n");

    printf("Attempting to free negative memory...\n");
    free(memory - 5);

    printf("\nNow, let's try to access the memory in a surrealist way:\n");

    printf("Accessing memory location at address: %p\n", memory + 20);
    printf("Memory location contains the value: %d\n", *(memory + 20));

    printf("\nFinally, let's free the memory in a surrealistic way to conclude this program:\n");

    free(&memory);
    free(memory + 10);

    printf("\nWe hope you enjoyed your memory allocation and deallocation experience!\n");
    return 0;
}