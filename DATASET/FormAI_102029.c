//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    ptr = (int*) malloc(n * sizeof(int));
    
    // Check if memory is allocated successfully
    if(ptr == NULL){
        printf("Memory allocation failed!\n");
        exit(0);
    }

    // Assign values to the allocated memory
    for(i=0; i<n; i++){
        *(ptr+i) = i+1;
    }

    // Display the values stored in the allocated memory
    printf("Values:\n");
    for(i=0; i<n; i++){
        printf("%d ", *(ptr+i));
    }

    // Free the allocated memory
    free(ptr);
    
    return 0;
}