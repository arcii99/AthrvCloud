//FormAI DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, *ptr;
    
    // ask for user input
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    // allocate memory dynamically
    ptr = (int*) malloc(size * sizeof(int));
    
    // check if allocation was successful
    if (ptr == NULL) {
        printf("Error: Memory not allocated");
        exit(0);
    }
    
    // assign values to array
    printf("Enter array elements:\n");
    for (int i=0; i<size; i++) {
        scanf("%d", &ptr[i]);
    }
    
    // print array elements
    printf("Array elements are:\n");
    for (int i=0; i<size; i++) {
        printf("%d ", ptr[i]);
    }
    
    // deallocate memory
    free(ptr);

    return 0;
}