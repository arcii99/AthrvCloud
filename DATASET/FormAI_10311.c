//FormAI DATASET v1.0 Category: Memory management ; Style: Alan Touring
/* Alan Turing style memory management example program */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr;
    
    printf("How many integers do you want to allocate memory for? ");
    int count;
    scanf("%d", &count);
    
    // Allocate memory dynamically
    ptr = (int*) malloc(count * sizeof(int));
    
    // Check if memory allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        exit(0);
    }
    
    printf("Enter %d integers:\n", count);
    
    // Take input from the user
    for (int i = 0; i < count; i++) {
        scanf("%d", ptr + i);
    }
    
    printf("The integers you entered are:\n");
    
    // Display the entered integers
    for (int i = 0; i < count; i++) {
        printf("%d ", *(ptr + i));
    }
    
    // Release the allocated memory
    free(ptr);
    
    printf("\nMemory freed successfully. Exiting program.\n");
    return 0;
}