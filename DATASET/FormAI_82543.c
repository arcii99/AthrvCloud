//FormAI DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// function to allocate memory to the pointer
void allocateMemory(int **ptr, int size) {
    // allocating memory using malloc
    *ptr = (int*) malloc(size*sizeof(int));
}

int main() {
    int *ptr;
    int size;

    // asking user for size of array
    printf("Enter the size of array: ");
    scanf("%d", &size);

    // allocating memory using the function
    allocateMemory(&ptr, size);

    // initializing the array
    for(int i=0; i<size; i++){
        *(ptr+i) = i;
    }

    // displaying the array
    printf("The elements of the array are: ");
    for(int i=0; i<size; i++){
        printf("%d ", *(ptr+i));
    }

    // deallocating the memory using free() function
    free(ptr);
    ptr = NULL;

    return 0;
}