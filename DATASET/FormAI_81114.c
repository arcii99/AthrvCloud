//FormAI DATASET v1.0 Category: Memory management ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello and welcome to our memory management program!\n");
    printf("We're going to allocate some memory and make the most of it!\n");

    int *memory_block = malloc(sizeof(int) * 10);

    if (memory_block == NULL) {
        printf("Oh no! Memory allocation failed. Please try again later.\n");
        return 1;
    }

    printf("Memory allocation successful! Let's fill it up with some numbers.\n");

    for (int i = 0; i < 10; i++) {
        memory_block[i] = i * 5;
    }

    printf("Numbers inserted successfully. Here they are:\n");

    for (int i = 0; i < 10; i++) {
        printf("%d\n", memory_block[i]);
    }

    printf("Now let's free up some memory and get ready for more fun!\n");

    free(memory_block);

    printf("Memory freed successfully. Let's allocate some more and start anew.\n");

    int *new_memory_block = calloc(15, sizeof(int));

    if (new_memory_block == NULL) {
        printf("Oh no! Memory allocation failed. Please try again later.\n");
        return 1;
    }

    printf("Memory allocation successful! Let's give it some values again.\n");

    for (int i = 0; i < 15; i++) {
        new_memory_block[i] = i * 2;
    }

    printf("Values inserted successfully. Here they are:\n");

    for (int i = 0; i < 15; i++) {
        printf("%d\n", new_memory_block[i]);
    }

    printf("We've had so much fun with memory management today. Time to free up all of our memory and say goodbye!\n");

    free(new_memory_block);

    return 0;
}