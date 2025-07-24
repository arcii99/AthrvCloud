//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr; // Define an integer pointer
    int size; // Define the size of the dynamic memory allocation
    
    printf("Enter the size of the integer array: ");
    scanf("%d", &size); // Get the size from user
    
    // Allocate memory dynamically using malloc function
    ptr = (int*) malloc(size * sizeof(int)); 
    
    if (ptr == NULL) // Check if memory allocation is successful or not
    {
        printf("Memory allocation failed");
        exit(0); // Terminate program if memory allocation fails
    }
    
    printf("Memory allocation successful");
    
    int sum = 0; // Define a variable to hold the sum of the integers
    
    for (int i = 0; i < size; i++) {
        printf("Enter element no. %d: ", i+1);
        scanf("%d", &ptr[i]); // Get each element from the user
        sum += ptr[i]; // Add up each element to the sum variable
    }
    
    printf("The sum of the elements in the array is: %d", sum); // Display the sum of the elements in the array
    
    // Free up the dynamically allocated memory
    free(ptr);
    
    return 0; // End the program
}