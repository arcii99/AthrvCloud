//FormAI DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an integer
    int* num_ptr = (int*) malloc(sizeof(int));
    
    // Check if memory allocation was successful
    if (num_ptr != NULL) {
        // Memory allocation successful
        printf("Thank you for allocating memory for an integer!\n");
        printf("Enter an integer value: ");
        scanf("%d", num_ptr);
        printf("You entered: %d\n", *num_ptr);
        
        // Deallocate memory
        free(num_ptr);
        printf("Thank you for deallocating memory!\n");
    }
    else {
        // Memory allocation unsuccessful
        printf("Oops! Something went wrong with memory allocation.\n");
        printf("Thank you for trying, I hope you have a great day!\n");
    }
    
    return 0;
}