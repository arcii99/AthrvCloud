//FormAI DATASET v1.0 Category: Memory management ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main() {
    int *memory_location;   // a variable to store memory location
    int allocation_size;    // variable to hold the size of allocated memory

    printf("Welcome to the Memory Allocation in C program!\n");
    printf("We will generate a random number for the size of memory allocation\n");
    printf("Now, let's spin the wheel...\n");

    time_t t;
    srand((unsigned) time(&t));   // initializing random seed
    allocation_size = rand() % 100 + 1;   // generating random number between 1 to 100

    printf("You won %d bytes of memory allocation!\n", allocation_size);
    printf("Now let's allocate the memory...\n");

    memory_location = (int*)malloc(allocation_size * sizeof(int));   // allocating memory using malloc()

    if(memory_location == NULL) {
        printf("Oops! Failed to allocate memory. Better luck next time.\n");
        exit(1);
    }
    printf("Memory allocated successfully at %p location!\n", memory_location);

    printf("Let's store some integers in the allocated memory!\n");

    for(int i = 0; i < allocation_size; i++) {
        *(memory_location + i) = rand() % 100 + 1;   // generating random number between 1 to 100 and storing it in allocated memory
    }

    printf("Integers stored successfully in the memory!\n");

    printf("Now, let's print the stored integers in the allocated memory\n");

    for(int i = 0; i < allocation_size; i++) {
        printf("%d ", *(memory_location + i));   // printing the integers stored in the allocated memory
    }

    printf("\nOperation completed successfully! Now, it's time to free the allocated memory. Bye bye...\n");

    free(memory_location);   // freeing the allocated memory

    return 0;
}