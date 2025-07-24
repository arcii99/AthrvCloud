//FormAI DATASET v1.0 Category: Memory management ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
    int *ptr = (int*) malloc(SIZE * sizeof(int));
    
    if (ptr == NULL) {
        printf("Error: Failed to allocate memory.");
        return 1;
    }
    
    printf("Initializing array with numbers 1 to 10.\n");
    for (int i = 0; i < SIZE; i++) {
        *(ptr + i) = i + 1;
    }
    
    printf("Array contains:");
    for (int i = 0; i < SIZE; i++) {
        printf(" %d", *(ptr + i));
    }
    printf("\n");
    
    ptr = realloc(ptr, (SIZE + 5) * sizeof(int));
    
    if (ptr == NULL) {
        printf("Error: Failed to reallocate memory.");
        return 1;
    }
    
    printf("Adding 5 more numbers to array.\n");
    for (int i = SIZE; i < SIZE + 5; i++) {
        *(ptr + i) = i + 1;
    }
    
    printf("Array now contains:");
    for (int i = 0; i < SIZE + 5; i++) {
        printf(" %d", *(ptr + i));
    }
    printf("\n");
    
    free(ptr);
    
    return 0;
}