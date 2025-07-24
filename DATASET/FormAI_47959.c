//FormAI DATASET v1.0 Category: Memory management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i, *ptr;    // Declare variables
    
    printf("Enter the number of elements: ");    // Prompt user for input
    scanf("%d", &size);    // Read size from user
    
    ptr = (int*) malloc(size * sizeof(int));    // Allocate memory dynamically
    
    if(ptr == NULL) {    // Check if memory allocation is successful
        printf("Memory Allocation Failed!\n");
        exit(0);    // Exit program
    }
    
    printf("Enter %d integers:\n", size);    // Prompt user to enter integers
    
    for(i = 0; i < size; i++) {
        scanf("%d", &ptr[i]);    // Read integers from user
    }
    
    printf("The integers entered are: ");
    
    for(i = 0; i < size; i++) {
        printf("%d ", ptr[i]);    // Print the integers entered
    }
    
    free(ptr);    // Free memory
    
    return 0;
}