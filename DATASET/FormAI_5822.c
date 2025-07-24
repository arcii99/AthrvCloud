//FormAI DATASET v1.0 Category: Error handling ; Style: Donald Knuth
// Error handling example program in a Donald Knuth style

#include <stdio.h>
#include <stdlib.h>

// Function to print error message and exit program
void error(char* message) {
    printf("Error: %s\n", message);
    exit(1);
}

int main() {
    int nums[5] = {1, 2, 3, 4, 5};
    int index;
    
    printf("Enter an array index: ");
    scanf("%d", &index);
    
    // Check if index is within bounds
    if (index < 0 || index >= 5)
        error("Index out of bounds");
    
    // Print value at specified index
    printf("Value at index %d is %d\n", index, nums[index]);
    
    return 0;
}