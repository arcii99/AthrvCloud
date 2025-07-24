//FormAI DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 5, i;
    int *ptr = (int *)calloc(size, sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    } 
    printf("Memory allocated successfully!\n");

    for (i = 0; i < size; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &*(ptr+i));
    }

    printf("\nElements in array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", *(ptr+i));
    }

    // Reallocation of memory
    int new_size = 10;
    ptr = (int *)realloc(ptr, new_size * sizeof(int));
    if (ptr == NULL) {
        printf("\nMemory reallocation failed");
        exit(1);
    }

    printf("\nMemory reallocation successful!\n");

    for (i = size; i < new_size; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &*(ptr+i));
    }

    printf("\nElements in array: ");
    for (i = 0; i < new_size; i++) {
        printf("%d ", *(ptr+i));
    }

    free(ptr);
    printf("\nMemory deallocated successfully!");
    return 0;
}